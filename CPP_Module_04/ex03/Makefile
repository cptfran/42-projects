.PHONY: all clean fclean re

NAME = AMateria
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all