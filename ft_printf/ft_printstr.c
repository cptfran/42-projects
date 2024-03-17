/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:29:07 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:20:19 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_printstr
 * --------------------
 * Prints a string to the standard output. If the string is NULL, it prints "(null)".
 *
 *  str: The string to print.
 *
 *  returns: The number of characters printed. If the string is NULL, it returns 6 (the number of characters in "(null)").
 */
int	ft_printstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
