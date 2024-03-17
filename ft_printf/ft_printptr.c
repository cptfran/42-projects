/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:55:27 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:19:59 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_ptrlen
 * --------------------
 * Calculates the length of a pointer address when represented in hexadecimal.
 *
 *  n: The pointer address to calculate the length of.
 *
 *  returns: The length of the pointer address in hexadecimal.
 */
int	ft_ptrlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

/*
 * Function:  ft_puthexa
 * --------------------
 * Prints a pointer address to the standard output in hexadecimal.
 *
 *  n: The pointer address to print.
 */
void	ft_puthexa(uintptr_t n)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16);
		ft_puthexa(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
			ft_putchar_fd(n + 'W', 1);
	}
}

/*
 * Function:  ft_printptr
 * --------------------
 * Prints a pointer address to the standard output.
 *
 *  ptr: The pointer address to print.
 *
 *  returns: The number of characters printed.
 */
int	ft_printptr(unsigned long ptr)
{
	int	ptr_len;

	ptr_len = 0;
	ptr_len += write(1, "0x", 2);
	if (ptr == 0)
		ptr_len += write(1, "0", 1);
	else
	{
		ft_puthexa(ptr);
		ptr_len += ft_ptrlen(ptr);
	}
	return (ptr_len);
}
