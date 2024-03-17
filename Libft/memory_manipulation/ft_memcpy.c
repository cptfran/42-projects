/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:50:15 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:45 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcpy() function copies n bytes from memory area src to memory area dst.
// If dst and src overlap, behavior is undefined.  Applications in which dst 
// and src might overlap should use memmove(3) instead.

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	while (i < length)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    src[7] = "example";
// 	char    dest[7];
// 	int i;

// 	i = 0;
// 	ft_memcpy(dest, src, 4);
// 	while (i < 4)
// 	{
// 		printf("%c", dest[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }