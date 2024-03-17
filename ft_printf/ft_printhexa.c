/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:51:28 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:17:15 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_hexalen
 * --------------------
 * Calculates the length of a hexadecimal number.
 *
 *  n: The number to calculate the length of.
 *
 *  returns: The length of the hexadecimal number.
 */
int	ft_hexalen(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

/*
 * Function:  ft_putsizedhexa
 * --------------------
 * Prints a hexadecimal number of a certain size.
 *
 *  n: The number to print.
 *  format: The format to print the number in.
 */
void	ft_putsizedhexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_putsizedhexa(n / 16, format);
		ft_putsizedhexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(n + 87, 1);
			if (format == 'X')
				ft_putchar_fd(n + 55, 1);
		}
	}
}

/*
 * Function:  ft_printhexa
 * --------------------
 * Prints a hexadecimal number to the standard output.
 *
 *  n: The number to print.
 *  sign: The sign that determines the format for printing ('x' for lowercase, 'X' for uppercase).
 *
 *  returns: The number of characters printed.
 */
int	ft_printhexa(unsigned int n, const char sign)
{
	int	hexa_len;

	hexa_len = 0;
	if (n == 0)
		hexa_len += write(1, "0", 1);
	else
	{
		ft_putsizedhexa(n, sign);
		hexa_len += ft_hexalen(n);
	}
	return (hexa_len);
}
