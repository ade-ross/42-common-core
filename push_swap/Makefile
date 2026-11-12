CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
		ft_lstsearchwnext.c ft_lstsize.c pa_pb.c\
		rr.c rrr.c ss.c\
		populate_st_a.c \
		populate_st_b.c \
		smallest.c \
		find_best_and_push.c \
		find_best_idx_to_move.c \
		sort.c \
		sort_for_three.c \
		create_list.c \
		ft_printf.c \
		other_printf_fts.c \
		ft_lstdelone.c \
		ft_atoi.c \
		ft_lstiter_mod.c \
		other_utils.c \

BONUS_SRCS = checker_bonus.c \
			pa_pb_bonus.c rr_bonus.c \
			rrr_bonus.c ss_bonus.c \
			ft_strncmp_bonus.c \
			get_next_line_utils_bonus.c \
			get_next_line_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) $(OBJ) main.o -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ) $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJS) -o $(BONUS_NAME)

main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJS) main.o

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
