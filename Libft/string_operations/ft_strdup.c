/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:39:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:40:36 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The strdup() function allocates sufficient memory for a copy of the string
//  s1, does the copy, and returns a pointer to it.  The pointer may 
// subsequently be used as an argument to the function free(3).

#include "../libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	ptr = (char *)malloc(sizeof(char) * (j + 1));
	if (!ptr)
		return (NULL);
	while (i < j)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    str[8] = "example";

// 	printf("%p\n", ft_strdup(str));
// 	printf("%s\n", ft_strdup((char *)str));
// 	return (0);
// }