#!/bin/bash
set -e

# Initialize MariaDB data directory if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB data directory..."
    mariadb-install-db --user=mysql --ldata=/var/lib/mysql > /dev/null
fi

# Start MariaDB temporarily in the background
echo "Starting MariaDB temporarily for setup..."
mysqld_safe --datadir=/var/lib/mysql &
pid="$!"

# Wait for MariaDB to be ready
echo "Waiting for MariaDB to be ready..."
until mysqladmin ping -h localhost --silent; do
    sleep 2
done
echo "MariaDB is ready!"

# Create WordPress database and user
echo "Setting up WordPress database and user..."
mysql -u root <<-EOSQL
    CREATE DATABASE IF NOT EXISTS \`${WORDPRESS_DB_NAME}\`;
    CREATE USER IF NOT EXISTS '${WORDPRESS_DB_USER}'@'%' IDENTIFIED BY '$(cat /run/secrets/db_password)';
    GRANT ALL PRIVILEGES ON \`${WORDPRESS_DB_NAME}\`.* TO '${WORDPRESS_DB_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

echo "WordPress database '${WORDPRESS_DB_NAME}' and user '${WORDPRESS_DB_USER}' set up successfully."

# Shut down the temporary MariaDB instance
echo "Shutting down temporary MariaDB server..."
mysqladmin -u root shutdown

# Start MariaDB in the foreground (container main process)
echo "Starting MariaDB in foreground..."
exec mysqld_safe --datadir=/var/lib/mysql
