# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 20:41:49 by sfrankie          #+#    #+#              #
#    Updated: 2023/12/14 17:54:23 by sfrankie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = *.h get_next_line/*.h

SRCS = *.c get_next_line/*.c

OBJS = $(SRCS:%.c=%.o)

LIBFT_PATH = ..
LIBFT = -L$(LIBFT_PATH) -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	ar rcs $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(OBJS)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re phony