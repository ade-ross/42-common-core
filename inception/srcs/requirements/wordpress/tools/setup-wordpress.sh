#!/bin/bash
set -e

# Load WordPress admin credentials and export them
if [ -f /run/secrets/credentials ]; then
    set -a
    . /run/secrets/credentials
    set +a
fi

# Wait for MariaDB
echo "Waiting for MariaDB..."
until mysql -h"$WORDPRESS_DB_HOST" -u"$WORDPRESS_DB_USER" --password="$(cat /run/secrets/db_password)" -e "SELECT 1" &> /dev/null
do
    sleep 2
done
echo "MariaDB is ready"

cd /var/www/html

export HTTP_HOST="$DOMAIN_NAME"

# Setup WordPress if not configured
if [ ! -f wp-config.php ]; then
    echo "Configuring WordPress..."
    wp config create \
        --allow-root \
        --dbname="$WORDPRESS_DB_NAME" \
        --dbuser="$WORDPRESS_DB_USER" \
        --dbpass="$(cat /run/secrets/db_password)" \
        --dbhost="$WORDPRESS_DB_HOST" \
        --path=/var/www/html
fi

# Add Redis caching constants if not already in wp-config.php
WP_CONFIG_FILE="/var/www/html/wp-config.php"

if ! grep -q "WP_REDIS_HOST" "$WP_CONFIG_FILE"; then
    echo "Adding Redis configuration to wp-config.php..."
    sed -i "/\/\* Add any custom values between this line/a \
define('FS_METHOD', 'direct');\\
define('WP_CACHE', true);\\
define('WP_REDIS_HOST', 'redis');\\
define('WP_REDIS_PORT', 6379);" "$WP_CONFIG_FILE"
fi

# Install WordPress core if not installed
if ! wp core is-installed --allow-root; then
    echo "Installing WordPress core..."
    wp core install \
        --allow-root \
        --url="https://$DOMAIN_NAME" \
        --title="Inception Project" \
   	--admin_user="$wp_admin_user" \
   	--admin_password="$wp_admin_password" \
   	--admin_email="$wp_admin_email" \
   	--skip-email
else
    echo "WordPress is already installed"
fi

# Ensure admin user exists
if ! wp user get "$wp_admin_user" --allow-root &>/dev/null; then
    echo "Creating admin user..."
    wp user create "$wp_admin_user" "$wp_admin_email" \
        --role=administrator \
        --user_pass="$wp_admin_password" \
        --allow-root
fi

# Ensure regular user exists
if ! wp user get wpuser --allow-root &>/dev/null; then
    echo "Creating regular user..."
    wp user create wpuser wpuser@example.com \
        --role=editor \
        --user_pass="$(cat /run/secrets/db_password)"\
        --allow-root
fi

echo "WordPress setup completed"

# Start PHP-FPM
exec php-fpm8.2 -F

