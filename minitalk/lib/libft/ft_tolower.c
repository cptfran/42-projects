/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:11:33 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 10:46:09 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The tolower() function converts an upper-case letter to the corresponding 
// lower-case letter.

int	ft_tolower(int x)
{
	if (x >= 'A' && x <= 'Z')
		return (x + 32);
	else
		return (x);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%c\n", ft_tolower('A'));
// 	return (0);
// }