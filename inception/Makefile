
NAME = inception

COMPOSE_FILE = srcs/docker-compose.yml
ENV_FILE = srcs/.env

all:	up

up:
	@echo "Starting Inception containers..."
	@docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE) up -d --build

down:
	@echo "Stopping Inception containers..."
	@docker compose -f $(COMPOSE_FILE) down

clean:
	@echo "Stopping Inception containers..."
	@docker compose -f $(COMPOSE_FILE) down

fclean:
	@echo "Removing containers..."
	@docker compose -f $(COMPOSE_FILE) down --rmi all --remove-orphans

re: clean all

ps:
	@docker compose -f $(COMPOSE_FILE) ps

logs:
	@docker compose -f $(COMPOSE_FILE) logs -f

prune:
	@echo "Pruning all Docker data..."
	@docker system prune -af

.PHONY: all up down clean fclean re ps logs prune
