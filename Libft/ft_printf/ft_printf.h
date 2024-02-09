/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:31:34 by sfrankie          #+#    #+#             */
/*   Updated: 2023/11/04 18:12:07 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

//int		check_args(const char *str, va_list *args);
int		ft_choose_format(va_list *args, const char sign);
int		ft_hexalen(size_t n);
int		ft_nbrlen(int n);
int		ft_printchar(int c);
int		ft_printf(const char *str, ...);
int		ft_printhexa(unsigned int n, const char sign);
int		ft_printpercent(void);
int		ft_printptr(unsigned long ptr);
int		ft_printstr(char *str);
int		ft_printunbr(unsigned int n);
int		ft_printnbr(int n);
int		ft_ptrlen(uintptr_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_puthexa(uintptr_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putsizedhexa(unsigned int n, const char format);
void	ft_putstr_fd(char *s, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_strlen(const char *str);
int		ft_unbrlen(unsigned int n);

#endif