FROM debian:bookworm

# Aggiorna e installa PHP + estensioni necessarie
RUN apt-get update && apt-get install -y \
    tini \
    php \
    php-mysqli \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Crea directory per Adminer
WORKDIR /var/www/html

COPY adminer.php ./adminer.php

# Imposta variabili d'ambiente
ENV ADMINER_DEFAULT_SERVER=mariadb

# Espone la porta 8080
EXPOSE 8080

ENTRYPOINT ["/usr/bin/tini", "--"]
CMD ["php", "-S", "0.0.0.0:8080", "adminer.php"]
