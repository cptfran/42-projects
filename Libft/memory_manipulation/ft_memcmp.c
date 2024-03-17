/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:55:09 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:42 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcmp() function compares byte string s1 against byte string s2.
//   Both strings are assumed to be n bytes long.

#include "../libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	printf("%i\n", memcmp("example", "m", 20));
// 	printf("%i\n", ft_memcmp("example", "m", 20));
// 	return (0);
// }