# ==========================
# Dockerfile for MariaDB
# ==========================
FROM debian:bookworm

# Install MariaDB server
RUN apt-get update && apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Copy optional custom MariaDB config
COPY conf/my.cnf /etc/mysql/my.cnf

# Copy setup script into the image
COPY tools/setup-mariadb.sh /usr/local/bin/setup-mariadb.sh
RUN chmod +x /usr/local/bin/setup-mariadb.sh

# Create a volume directory for persistent data
VOLUME ["/var/lib/mysql"]

# Expose default MySQL port
EXPOSE 3306

# Run the setup script (which initializes DB then launches mysqld)
ENTRYPOINT ["/usr/local/bin/setup-mariadb.sh"]
