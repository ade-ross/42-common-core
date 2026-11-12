# ===============================
# Dockerfile for NGINX container
# ===============================
FROM debian:bookworm

# Install nginx and openssl
RUN apt-get update && apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# Create directories for SSL certs and configs
RUN mkdir -p /etc/nginx/conf.d

# Copy configuration and certificates
COPY conf/default.conf /etc/nginx/conf.d/default.conf
COPY tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

# Expose ports
EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]
