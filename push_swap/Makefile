# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:56:04 by sfrankie          #+#    #+#              #
#    Updated: 2024/01/12 17:00:59 by sfrankie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re phony

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/error.c src/error2.c src/utils.c src/utils2.c src/utils3.c \
		src/rules.c src/rules2.c src/rules3.c src/sort.c src/sort2.c src/sort3.c

OBJ = $(SRC:.c=.o)

all: libft $(NAME)

libft:
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all