/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:18:59 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 13:42:05 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
// NUL-terminating the result if dstsize is not 0.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != 0)
		srclen++;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    dst[10];

// 	printf("%zu\n", ft_strlcpy(dst, "Hello World", 10));
// 	return (0);
// }