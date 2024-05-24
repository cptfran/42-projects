.PHONY: all clean fclean re

NAME = Serializer
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = A.cpp B.cpp C.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all