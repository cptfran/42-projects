/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:17:14 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:30:25 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../lib/libft/libft.h"
#include "../../lib/ft_printf/ft_printf.h"
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define GREY  "\x1B[94m"
#define RESET "\x1B[0m"

/*
 * Function: bit_send
 * ----------------------------
 *   Sends a bit to the server process identified by the PID using UNIX signals.
 *
 *   bit: The bit to be sent. If it's 1, SIGUSR1 is sent; if it's 0, SIGUSR2 is sent.
 *   pid: The PID of the server process.
 *
 *   Returns: void
 */
void	bit_send(int bit, pid_t pid)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

/*
 * Function: char_split_send
 * ----------------------------
 *   Splits a character into bits and sends each bit to the server process identified by the PID.
 *
 *   c: The character to be split and sent.
 *   pid: The PID of the server process.
 *
 *   Returns: void
 */
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

/*
 * Function: str_split_send
 * ----------------------------
 *   Sends each character of the string to the server process identified by the PID.
 *
 *   str: The string to be sent.
 *   pid: The PID of the server process.
 *
 *   Returns: void
 */
void	str_split_send(const char *str, pid_t pid)
{
	while (*str)
		char_split_send(*str++, pid);
	char_split_send(0, pid);
}

/*
 * Function: main
 * ----------------------------
 *   The main function of the client program. It checks the command line arguments,
 *   converts the PID from a string to an integer, and sends the message to the server.
 *
 *   argc: The number of command line arguments.
 *   argv: The array of command line arguments.
 *
 *   Returns: 0 if the message is sent successfully, 1 otherwise.
 */
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
