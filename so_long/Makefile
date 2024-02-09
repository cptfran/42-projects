# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:38:48 by sfrankie          #+#    #+#              #
#    Updated: 2024/01/27 16:14:57 by sfrankie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re phony

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/textures.c src/controls.c src/controls_2.c src/map.c \
	src/map_2.c src/map_3.c utils/utils.c utils/utils_2.c utils/utils_3.c \
	utils/utils_4.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -Llibft -lft

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@
	
clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all