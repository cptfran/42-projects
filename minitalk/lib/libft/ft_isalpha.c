/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:36:37 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 14:53:10 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isalpha() function tests for any character for which isupper(3) or
//  islower(3) is true.  The value of the argument must be representable as an
//  unsigned char or the value of EOF.

int	ft_isalpha(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int    i;

// 	printf("enter an integer: ");
// 	scanf("%i", &i);

// 	if (ft_isalpha(i))
// 	{
// 		printf("1 - alphabetic character\n");
// 	} else
// 	{
// 		printf("0 - non-alphabetic character\n");
// 	}

// 	return (0);
// }