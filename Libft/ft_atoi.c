/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:16:32 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/29 18:04:37 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The atoi() function converts the initial portion of the string pointed to 
// by str to int representation

int	ft_atoi(const char *str)
{
	int			i;
	int			plusormin;
	long long	total;

	i = 0;
	plusormin = 1;
	total = 0;
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\f'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plusormin = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		total = total * 10 + (str[i++] - '0');
	total *= plusormin;
	if (total > 2147483647 || total < -2147483648)
		return (0);
	return (total);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	printf("%i\n", atoi("-1285125"));
// 	printf("%i\n", ft_atoi("-1285125"));
// 	return (0);
// }