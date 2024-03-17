/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:41:46 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:16:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_choose_format
 * --------------------
 * Chooses the correct format for printing based on the provided sign.
 *
 *  args: A pointer to the list of arguments.
 *  sign: The sign that determines the format for printing.
 *
 *  returns: The number of characters printed.
 */
int	ft_choose_format(va_list *args, const char sign)
{
	int			count;

	count = 0;
	if (sign == 'c')
		count = ft_printchar(va_arg(*args, int));
	else if (sign == 's')
		count = ft_printstr(va_arg(*args, char *));
	else if (sign == 'p')
		count = ft_printptr(va_arg(*args, unsigned long));
	else if (sign == 'd' || sign == 'i')
		count = ft_printnbr(va_arg(*args, int));
	else if (sign == 'u')
		count = ft_printunbr(va_arg(*args, unsigned int));
	else if (sign == 'x' || sign == 'X')
		count = ft_printhexa(va_arg(*args, unsigned int), sign);
	else if (sign == '%')
		count = ft_printpercent();
	return (count);
}

/*
 * Function:  ft_printf
 * --------------------
 * A simplified version of the printf function. It formats and prints data to the standard output.
 *
 *  str: The format string that specifies how subsequent arguments are converted for output.
 *
 *  returns: The number of characters printed.
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_choose_format(&args, str[i]);
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	return (va_end(args), count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%%%c%%%s%%%d%%%i%%%x%%%u%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	ft_printf("%%%c%%%s%%%d%%%i%%%x%%%u%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	return (0);
// }