/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:41:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:11 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The strnstr() function locates the first occurrence of the null-terminated
//  string needle in the string haystack, where not more than len characters are
//  searched.  Characters that appear after a `\0' character are not searched

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < size)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < size)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%p\n", ft_strnstr("example", "ple", 7));
// 	return (0);
// }