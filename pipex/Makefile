CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = pipex

BONUS_NAME = pipex_bonus

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

SRC = ft_strcmp.c ft_strnstr_mod.c \
	other_utils.c utils.c

BONUS_SRCS = pipex_bonus.c pipex_bonus_h.c

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(OBJ) pipex.o
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) pipex.o $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(OBJ) $(BONUS_OBJS)
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJS) pipex.o
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

.PHONY: all clean fclean re bonus
