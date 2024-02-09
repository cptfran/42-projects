/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:52 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 14:53:17 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isalnum() function tests for any character for which isalpha(3) 
// or isdigit(3) is true. The value of the argument must be 
// representable as an unsigned char or the value of EOF.

int	ft_isalnum(int i)
{
	unsigned char	uc;

	uc = (unsigned char)(i);
	if ((uc >= '0' && uc <= '9') || (uc >= 'A' && uc <= 'Z')
		|| (uc >= 'a' && uc <= 'z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	int    i;

// 	printf("enter an integer: ");
// 	scanf("%i", &i);

// 	if (ft_isalnum(i))
// 	{
// 		printf("1 - alnum\n");
// 	} else
// 	{
// 		printf("0 - not an alnum\n");
// 	}

// 	return (0);
// }