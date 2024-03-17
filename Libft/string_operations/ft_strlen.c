/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:52 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 12:40:59 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    *str = malloc(100 * sizeof(char));

// 	printf("enter string: ");
// 	scanf("%s", str);
// 	printf("string length - %i\n", ft_strlen(str));
// 	free(str);
// 	return (0);
// }