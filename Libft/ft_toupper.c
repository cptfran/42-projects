/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:24:09 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 10:46:53 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The toupper() function converts a lower-case letter to the corresponding 
// upper-case letter.

int	ft_toupper(int x)
{
	if (x >= 'a' && x <= 'z')
		return (x - 32);
	else
		return (x);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// 	return (0);
// }