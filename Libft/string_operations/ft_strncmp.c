/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:31:54 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:07 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strncmp() function compares not more than n characters.  Because 
// strncmp() is designed for comparing strings rather than binary data,
//  characters that appear after a `\0' character are not compared.

#include "../libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;

	i = 0;
	if (str1[i] == '\0' && size > 0)
		return (0 - (unsigned char)str2[i]);
	else if (str2[i] == '\0' && size > 0)
		return ((unsigned char)str1[i]);
	while (i < size)
	{
		if (str1[i] == '\0' || str2[i] == '\0'
			|| (unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	printf("%i\n", strncmp("example", "ac", 20));
// 	printf("%i\n", ft_strncmp("exampXe", "ac", 20));
// 	return (0);
// }