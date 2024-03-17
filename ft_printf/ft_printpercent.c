/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:19:13 by sfrankie          #+#    #+#             */
/*   Updated: 2024/03/17 13:18:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_printpercent
 * --------------------
 * Prints a percent symbol (%) to the standard output.
 *
 *  returns: Always returns 1. This is because a single percent symbol is always printed, so the number of printed characters is always 1.
 */
int	ft_printpercent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
