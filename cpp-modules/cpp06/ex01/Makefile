
NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRC = main.cpp \
		Data.cpp \
		Serializer.cpp \

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
