/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:10:26 by sfrankie          #+#    #+#             */
/*   Updated: 2024/02/11 17:27:58 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_iferror(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!ft_ifdigitarr(argv + 1))
		return (1);
	return (0);
}

int	ft_ifdigitstr(char *argv)
{
	if (!*argv || *argv == '0')
		return (0);
	while (*argv)
	{
		if (ft_is_plus_digit(*argv) || *argv == ' ')
			argv++;
		else
			return (0);
	}
	return (1);
}

int	ft_ifdigitarr(char **argv)
{
	while (*argv)
	{
		if (!ft_ifdigitstr(*argv++))
			return (0);
	}
	return (1);
}

int	ft_is_plus_digit(int i)
{
	if (i <= '9' && i >= '0')
		return (1);
	return (0);
}
