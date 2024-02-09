/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:23:52 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/04 09:19:30 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Outputs the integer ’n’ to the given file
// descriptor.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_putnbr_fd(-325236, 1);
// 	printf("\n");
// 	return (0);
// }