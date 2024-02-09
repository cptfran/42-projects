/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:51:28 by sfrankie          #+#    #+#             */
/*   Updated: 2023/08/28 17:07:54 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
