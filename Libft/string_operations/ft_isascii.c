/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:52 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isascii() function tests for an ASCII character, which is any character
//  between 0 and octal 0177 inclusive.

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int    i;

// 	printf("enter an integer: ");
// 	scanf("%i", &i);

// 	if (ft_isascii(i))
// 	{
// 		printf("1 - ascii\n");
// 	} else
// 	{
// 		printf("0 - not an ascii\n");
// 	}

// 	return (0);
// }