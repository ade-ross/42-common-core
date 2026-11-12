# **************************************************************************** #
#                                   PORTAINER                                  #
# **************************************************************************** #

FROM debian:bookworm

# Prevent interactive prompts during build
ARG DEBIAN_FRONTEND=noninteractive

# Update system and install only necessary tools
RUN apt-get update && apt-get install -y --no-install-recommends \
        curl \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Create a directory for persistent data
RUN mkdir -p /data

# Download and install the latest Portainer binary
RUN curl -fsSL https://github.com/portainer/portainer/releases/download/2.33.2/portainer-2.33.2-linux-amd64.tar.gz \
    -o /tmp/portainer.tar.gz \
    && tar -xzf /tmp/portainer.tar.gz -C /usr/local/bin --strip-components=1 \
    && rm -rf /tmp/portainer.tar.gz

# Run Portainer
CMD ["portainer", "--data", "/data"]
