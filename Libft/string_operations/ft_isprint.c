/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:52 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 15:31:51 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isprint() function tests for any printing character, including space.
// The value of the argument must be representable as an unsigned char or the
//  value of EOF.

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int    i;

// 	printf("enter an integer: ");
// 	scanf("%i", &i);

// 	if (ft_isprint(i))
// 	{
// 		printf("1 - print\n");
// 	} else
// 	{
// 		printf("0 - not a print\n");
// 	}

// 	return (0);
// }