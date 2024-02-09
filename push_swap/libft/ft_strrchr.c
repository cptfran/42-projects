/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:38:34 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 19:54:00 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strrchr() function is identical to strchr(), except it locates the last
//  occurrence of c.

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	unsigned char	temp;
	const char		*last;
	int				*segfault;

	temp = (unsigned char)ch;
	last = NULL;
	if (str == NULL)
	{
		segfault = NULL;
		*segfault = 42;
	}
	while (*str != '\0')
	{
		if ((unsigned char)*str == temp)
			last = str;
		str++;
	}
	if (*str == '\0' && temp == '\0')
		return ((char *)str);
	return ((char *)last);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    str[8] = "exampxle";

// 	printf("%p\n", &str[1]);
// 	printf("%p\n", &str[5]);
// 	printf("%p\n", ft_strrchr(str, 'x'));
// 	return (0);
// }