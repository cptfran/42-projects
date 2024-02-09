# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 14:27:48 by sfrankie          #+#    #+#              #
#    Updated: 2023/12/13 10:28:40 by sfrankie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re run phony

all:
	@make -C lib/libft
	@make -C lib/ft_printf
	@make -C src/client
	@make -C src/server

clean:
	@make -C lib/libft clean
	@make -C lib/ft_printf clean
	@make -C src/client clean
	@make -C src/server clean

fclean:
	@make -C lib/libft fclean
	@make -C lib/ft_printf fclean
	@make -C src/client fclean
	@make -C src/server fclean

re:
	@make -C lib/libft re
	@make -C lib/ft_printf re
	@make -C src/client re
	@make -C src/server re

run: all
	@open -a Terminal ./src/client/
	@open -a Terminal ./src/server/server