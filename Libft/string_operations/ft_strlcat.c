/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:20:31 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:40:49 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strlcat() appends string src to the end of dst.  It will append at most 
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
//  dstsize is 0 or the original dst string was longer than dstsize 
// (in practice this should not happen as it means that either dstsize is 
// incorrect or that dst is not a proper string).

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	total;
	size_t	dstlen;
	size_t	srclen;
	char	*tmpsrc;

	i = 0;
	total = 0;
	dstlen = ft_strlen(dst);
	tmpsrc = (char *)src;
	srclen = ft_strlen(tmpsrc);
	if (dstlen < dstsize)
		total = dstlen + srclen;
	else
		total = srclen + dstsize;
	while (tmpsrc[i] != '\0' && (dstlen + 1) < dstsize)
	{
		dst[dstlen] = tmpsrc[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (total);
}

// #include <stdio.h>
// int main(void)
// {
// 	char dst[20] = "hello";
// 	printf("%zu\n", ft_strlcat(dst, "world", sizeof(dst)));
// 	printf("Concatenated string: %s\n", dst);
// 	return (0);
// }