.PHONY: all clean fclean re

NAME = zombie
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = newZombie.cpp Zombie.cpp main.cpp randomChump.cpp
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