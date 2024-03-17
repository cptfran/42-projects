/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:36:31 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:40:31 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strchr() function locates the first occurrence of c (converted to a char)
// in the string pointed to by s.  The terminating null character is considered
//  to be part of the string; therefore if c is `\0', the functions locate the
//   terminating `\0'.

#include "../libft.h"

char	*ft_strchr(const char *str, int x)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char)x;
	while (str[i] != '\0')
	{
		if (str[i] == temp)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == temp)
		return ((char *)&str[i]);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    str[8] = "example";

// 	printf("%p\n", &str[7]);
// 	printf("%p\n", &str[1]);
// 	printf("%p\n", ft_strchr(str, 'x'));
// 	return (0);
// }