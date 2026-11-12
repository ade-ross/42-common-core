
NAME = identifier

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRC = main.cpp \
		Base.cpp \

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
