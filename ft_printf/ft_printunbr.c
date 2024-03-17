/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:50:22 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:21:08 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_unbrlen
 * --------------------
 * Calculates the length of an unsigned number.
 *
 *  n: The unsigned number to calculate the length of.
 *
 *  returns: The length of the unsigned number.
 */
int	ft_unbrlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
 * Function:  ft_putunbr_fd
 * --------------------
 * Prints an unsigned number to a file descriptor.
 *
 *  n: The unsigned number to print.
 *  fd: The file descriptor to print to.
 */
void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/*
 * Function:  ft_printunbr
 * --------------------
 * Prints an unsigned number to the standard output.
 *
 *  n: The unsigned number to print.
 *
 *  returns: The number of characters printed.
 */
int	ft_printunbr(unsigned int n)
{
	ft_putunbr_fd(n, 1);
	return (ft_unbrlen(n));
}
