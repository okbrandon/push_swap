/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:25:57 by bsoubaig          #+#    #+#             */
/*   Updated: 2022/12/03 14:28:51 by bsoubaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_parse(const char *format, int i, va_list args);
int	ft_putpointer(unsigned long long n);
int	ft_puthexnbr(unsigned int n, int is_upper);
int	ft_putunsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);

#endif