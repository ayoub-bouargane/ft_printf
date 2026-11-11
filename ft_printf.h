/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:18:00 by aybouarg          #+#    #+#             */
/*   Updated: 2026/11/03 12:18:06 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_puthex(unsigned long n, char *base);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putstr(const char *s);
int	ft_putunsigned(unsigned int n);
int	ft_putptr(void *p);

#endif
