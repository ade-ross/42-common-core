#!/bin/bash
set -e

# Create a directory for SSL certificates
mkdir -p /etc/nginx/ssl
chmod 700 /etc/nginx/ssl

# Copy secrets to proper location
cp /run/secrets/server_crt /etc/nginx/ssl/server.crt
cp /run/secrets/server_key /etc/nginx/ssl/server.key
cp /run/secrets/static_crt /etc/nginx/ssl/static.crt
cp /run/secrets/static_key /etc/nginx/ssl/static.key

# Make sure permissions are tight
chmod 600 /etc/nginx/ssl/server.key
chmod 644 /etc/nginx/ssl/server.crt
chmod 600 /etc/nginx/ssl/static.key
chmod 644 /etc/nginx/ssl/static.crt

# Start nginx
exec nginx -g "daemon off;"
