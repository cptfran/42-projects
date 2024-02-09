/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:16:59 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/13 12:38:01 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../lib/ft_printf/ft_printf.h"

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
