#!/bin/bash
set -e

# Create FTP user at runtime
if ! id "$FTP_USER" &>/dev/null; then
    useradd -m "$FTP_USER" -s /bin/bash
    echo "$FTP_USER:$(cat $FTP_PASS)" | chpasswd
fi

# Add to www-data group
usermod -aG www-data $FTP_USER

# Fix WordPress directory permissions
chown -R www-data:www-data /var/www/html
chmod -R 775 /var/www/html

# Start vsftpd
exec /usr/sbin/vsftpd /etc/vsftpd.conf
