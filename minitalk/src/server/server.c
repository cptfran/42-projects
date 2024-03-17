/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:16:59 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:31:38 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../lib/ft_printf/ft_printf.h"

/*
 * Function: handle_signals
 * ----------------------------
 *   Handles the signals received from the client. It shifts the current character
 *   to the left, and if the signal is SIGUSR1, it sets the least significant bit of
 *   the character to 1. After 8 signals (which means a full character has been received),
 *   it writes the character to the standard output and resets the character and bit count.
 *
 *   sig: The signal received from the client.
 *
 *   Returns: void
 */
void	handle_signals(int sig)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c = c << 1;
	if (sig == SIGUSR2)
		;
	else if (sig == SIGUSR1)
		c = c | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

/*
 * Function: main
 * ----------------------------
 *   The main function of the server program. It sets up the signal handler and waits
 *   for signals from the client.
 *
 *   Returns: 0 if the server runs successfully, a non-zero value otherwise.
 */
int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = &handle_signals;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: failed setting up signal handler.\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
