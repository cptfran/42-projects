/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:49:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:18:03 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_nbrlen
 * --------------------
 * Calculates the length of a number.
 *
 *  n: The number to calculate the length of.
 *
 *  returns: The length of the number.
 */
int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
 * Function:  ft_printnbr
 * --------------------
 * Prints a number to the standard output.
 *
 *  n: The number to print.
 *
 *  returns: The number of characters printed.
 */
int	ft_printnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}
