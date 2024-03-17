/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:26:41 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:41:30 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The bzero() function writes n zeroed bytes to the string s.
// If n is zero, bzero() does nothing.

#include "../libft.h"

void	*ft_bzero(void *str, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

//#include <stdio.h>
// int main(void)
// {
// 	char    str[7] = "example";
// 	int i;

// 	i = 0;
// 	ft_bzero(str, 2);
// 	while (i < 7)
// 	{
// 		printf("%c", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }