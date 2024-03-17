/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:37:59 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:14:02 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_printchar
 * --------------------
 * Prints a character to the standard output.
 *
 *  c: The character to be printed.
 *
 *  returns: Always returns 1. This is because a single character is always printed, so the number of printed characters is always 1.
 */
int	ft_printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
