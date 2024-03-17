/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:08:08 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:40:27 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

#include "../libft.h"

static int	ft_wcount(char const *s, char c)
{
	int	count;
	int	i;
	int	len;

	count = 0;
	i = 0;
	len = ft_strlen((char *)s);
	while (i < len)
	{
		if (s[i] != c)
		{
			count++;
			while (i < len && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_gword(char const *s, char c, int index)
{
	int		wlen;
	int		i;
	int		j;
	char	*word;

	wlen = 0;
	i = index;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		wlen++;
	}
	word = (char *)malloc(sizeof(char) * (wlen + 1));
	if (!word)
		return (NULL);
	while (s[index] != '\0' && s[index] != c)
	{
		word[j] = s[index];
		j++;
		index++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_free(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		k;
	char	**arr;

	j = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			arr[k] = ft_gword(s, c, j);
			if (!arr[k])
				return (ft_free(arr));
			k++;
			while (s[j] != '\0' && s[j] != c)
				j++;
		}
		else
			j++;
	}
	arr[k] = NULL;
	return (arr);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%p\n", ft_split("42.wolfsburg.de", '.'));
// 	return (0);
// }