/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:45:50 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:53 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memset() function writes len bytes of value c 
// (converted to an unsigned char) to the string b.

#include "../libft.h"

void	*ft_memset(void *str, int i, size_t length)
{
	size_t	j;

	j = 0;
	while (j < length)
	{
		((unsigned char *)str)[j] = i;
		j++;
	}
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    str[10];
// 	int i;

// 	i = 0;
// 	ft_memset(str, 'B', 3);
// 	while (i < 10)
// 	{
// 		printf("%c, ", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }