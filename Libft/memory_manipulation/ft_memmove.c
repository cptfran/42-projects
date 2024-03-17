/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:34:03 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:48 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memmove() function copies len bytes from string src to string dst.  The
// two strings may overlap; the copy is always done in a non-destructive manner.

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t numofbytes)
{
	char	*sdest;
	char	*ssrc;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (dest);
	sdest = (char *)dest;
	ssrc = (char *)src;
	i = 0;
	if (sdest > ssrc)
	{
		while (numofbytes > 0)
		{
			sdest[numofbytes - 1] = ssrc[numofbytes - 1];
			numofbytes--;
		}
	}
	while (i < numofbytes)
	{
		sdest[i] = ssrc[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    src[10] = "example";
// 	ft_memmove(src + 1, src, 3);
// 	printf("%s\n", src);
// 	return (0);
// }