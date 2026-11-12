# ===================================
# Dockerfile for WordPress + PHP-FPM
# ===================================
FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php-fpm php-mysql php-cli php-curl php-xml php-gd php-mbstring php-redis wget unzip curl mariadb-client && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

# Download and extract WordPress
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz

# Copy custom FPM config
COPY conf/php-fpm.conf /etc/php/8.2/fpm/php-fpm.conf

# Install WP-CLI (command-line interface for WordPress)
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# Copy setup script
COPY tools/setup-wordpress.sh /usr/local/bin/setup-wordpress.sh
RUN chmod +x /usr/local/bin/setup-wordpress.sh

EXPOSE 9000

# Start setup script on container start
ENTRYPOINT ["setup-wordpress.sh"]
