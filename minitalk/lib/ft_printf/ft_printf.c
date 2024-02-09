/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:41:46 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/27 17:52:58 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	check_args(const char *str, va_list *args)
// {
// 	int			i;
// 	long long	y;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			i++;
// 			if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'x'
// 				|| str[i] == 'X')
// 				va_arg(*args, int);
// 			else if (str[i] == 'i' || str[i] == 'd' || str[i] == 'u')
// 			{
// 				y = va_arg(*args, long long);
// 				if (y < INT_MIN || y > INT_MAX)
// 					return (-1);
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }
// va_start(args, str);
// if (check_args(str, &args) == -1)
// 	return (ft_printstr("error: argument should be type of 'int'"), -1);
// va_end(args);

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
// 	printf("%i string %s string %u dd %c oo %d aa %x ooo %X eee %% aaa %p\n", 
// 		23, "smth", 2000, 'X', 3, 2000, 2000, "42325");
// 	ft_printf("%i string %s string %u dd %c oo %d aa %x ooo %X eee %% aaa %p\n",
// 		23, "smth", 2000, 'X', 3, 2000, 2000, "42325");
// 	return (0);
// }