/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:17:14 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/13 12:12:43 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../lib/libft/libft.h"
#include "../../lib/ft_printf/ft_printf.h"
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define GREY  "\x1B[94m"
#define RESET "\x1B[0m"

void	bit_send(int bit, pid_t pid)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	char_split_send(unsigned char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit_send((c >> i--) & 1, pid);
		usleep(50);
	}
}

void	str_split_send(const char *str, pid_t pid)
{
	while (*str)
		char_split_send(*str++, pid);
	char_split_send(0, pid);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf(RED "\nEnter data in correct format: \n" RESET);
		ft_printf(GREY "./client 'server PID' 'string'\n\n" RESET);
		ft_printf(GREEN "Hint: PID is visible in server terminal.\n\n" RESET);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf(RED "Error: Invalid PID.\n" RESET);
		return (1);
	}
	else
	{
		ft_printf(GREEN "Sending string: '%s'\n" RESET, argv[2]);
		str_split_send(argv[2], pid);
	}
	return (0);
}
