/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:34:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memchr() function locates the first occurrence of c 
// (converted to an unsigned char) in string s.

#include "../libft.h"

void	*ft_memchr(const void *str, int x, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)str)[i] == (unsigned char)x)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char    str[10] = "hello";

// 	printf("%p\n", memchr(str, 'l', 10));
// 	printf("%p\n", ft_memchr(str, 'l', 10));
// 	return (0);
// }