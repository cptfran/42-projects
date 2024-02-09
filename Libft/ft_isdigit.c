/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:52 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:19 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The isdigit() function tests for a decimal digit character.  Regardless of 
// locale, this includes the following characters only.

int	ft_isdigit(int i)
{
	if (i <= '9' && i >= '0')
		return (1);
	return (0);
}

//#include <stdio.h>
// int main(void)
// {
// 	int    i;

// 	printf("enter an integer: ");
// 	scanf("%i", &i);

// 	if (ft_isdigit(i))
// 	{
// 		printf("1 - digit\n");
// 	} else
// 	{
// 		printf("0 - not a digit\n");
// 	}

// 	return (0);
// }