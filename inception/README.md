# Inception

A small WordPress infrastructure run with Docker Compose. The rule of the project: no ready-made images. Every service is built from its own `Dockerfile` on top of `debian:bookworm` and configured by my own scripts.

## Services

```
                 :443 (TLS 1.2/1.3)
  browser ──────────▶ nginx ──fastcgi:9000──▶ wordpress (php-fpm) ──▶ mariadb
                        │                          │
                        └─ static site             └──▶ redis (object cache)

  bonus: ftp (vsftpd) on the WordPress volume · adminer · portainer
```

| Service | Role |
| --- | --- |
| **nginx** | The only entry point, on port 443, TLS 1.2/1.3 only. Serves WordPress through FastCGI and a second static site on its own server name. |
| **wordpress** | PHP-FPM with WP-CLI. On the first start the script creates `wp-config.php`, installs WordPress, creates an admin and an editor user, and points WordPress's cache settings at Redis. |
| **mariadb** | The database. The init script creates the database and the user from the environment and Docker secrets. |
| **redis** | Object cache for WordPress (bonus). |
| **ftp** | vsftpd with access to the WordPress files (bonus). |
| **adminer** | Web database admin, bound to `127.0.0.1` only (bonus). |
| **portainer** | Docker management UI, bound to `127.0.0.1` only (bonus). |

## Passwords and certificates

There are no passwords in the image, in the Compose file or in the environment. They are mounted as **Docker secrets** from a `secrets/` folder next to `srcs/`. That folder is not in this repository, so it has to be created before the first run:

```
secrets/
├── db_password.txt
├── db_root_password.txt
├── ftp_password.txt
├── credentials.txt        # wp_admin_user=… wp_admin_password=… wp_admin_email=…
└── ssl/
    ├── server.crt  server.key   # e.g. openssl req -x509 -nodes -newkey rsa:2048 …
    └── static.crt  static.key
```

The non-secret settings go in `srcs/.env`; see [`srcs/.env.example`](srcs/.env.example).

## Run

```bash
cp srcs/.env.example srcs/.env      # then create secrets/ as above
mkdir -p ~/data/{wordpress,mysql,static-site,portainer}   # bind-mounted volumes; adjust the paths in docker-compose.yml
make            # build and start
make down       # stop
```

Add `127.0.0.1 ade-ross.42.fr static-ade-ross.42.fr` to `/etc/hosts`, then open `https://ade-ross.42.fr`.
