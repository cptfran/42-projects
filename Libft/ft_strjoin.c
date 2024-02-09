/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:35:15 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 18:50:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	k;
	size_t	l;
	char	*scat;

	k = 0;
	l = 0;
	scat = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)(s1)) + ft_strlen((char *)(s2)) + 1));
	if (!scat)
		return (NULL);
	while (s1[k] != '\0')
	{
		scat[k] = s1[k];
		k++;
	}
	while (s2[l] != '\0')
	{
		scat[k] = s2[l];
		k++;
		l++;
	}
	scat[k] = '\0';
	return (scat);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%p\n", ft_strjoin("hello ", "world"));
// 	printf("%s\n", ft_strjoin("hello ", "world"));
// 	return (0);
// }