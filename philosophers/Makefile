CC = cc
CFLAGS = -Wall -Wextra -Werror
PTHREADFLAGS = -lpthread
NAME = philo

#BONUS_NAME =


SRC = main.c philosopher.c ft_atoi.c get_time.c \
		parsing.c initialize.c try_to_eat.c \
		first_and_second_fork.c \
		check_ph_are_alive.c
#BONUS_SRCS =

OBJ = $(SRC:.c=.o)

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PTHREADFLAGS) -o $(NAME)

#bonus: $(BONUS_NAME)

#$(BONUS_NAME): $(OBJ) $(BONUS_OBJS) $(LIBFT)
#		$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJ)  $(LIBFT) -o $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
