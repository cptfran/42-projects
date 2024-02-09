/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:22:03 by sfrankie          #+#    #+#             */
/*   Updated: 2023/12/01 17:54:44 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

#include "libft.h"

static int	ft_ischar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start_i;
	size_t	end_i;
	size_t	i;

	start_i = 0;
	end_i = ft_strlen((char *)s1) - 1;
	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start_i] != '\0' && ft_ischar(s1[start_i], set))
		start_i++;
	if (s1[start_i] == '\0')
		return (ft_strdup(""));
	while (end_i > start_i && ft_ischar(s1[end_i], set))
		end_i--;
	trimmed = (char *)malloc(sizeof(char)
			* (end_i - start_i + 2));
	if (!trimmed)
		return (NULL);
	while (start_i <= end_i)
		trimmed[i++] = s1[start_i++];
	trimmed[i] = '\0';
	return (trimmed);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%p\n", ft_strtrim("destrde", "de"));
// 	printf("%s\n", ft_strtrim("destrde", "de"));
// 	return (0);
// }