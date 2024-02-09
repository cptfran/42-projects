# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 12:17:23 by sfrankie          #+#    #+#              #
#    Updated: 2023/12/13 12:26:23 by sfrankie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = client.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ../../lib/libft
LIBFT = -L$(LIBFT_PATH) -lft
PRINTF_PATH = ../../lib/ft_printf
PRINTF_LIB = -L$(PRINTF_PATH) -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ $(LIBFT) $(PRINTF_LIB)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(LIBFT_PATH) -I$(PRINTF_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re phony