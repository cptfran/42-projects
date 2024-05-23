.PHONY: all clean fclean re

NAME = ScalarConverter
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = NumRange.cpp main.cpp Print.cpp ScalarConverter.cpp StringRecognition.cpp
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