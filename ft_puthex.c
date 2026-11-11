/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:31:01 by aybouarg          #+#    #+#             */
/*   Updated: 2026/11/07 16:31:02 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *base)
{
	int	i;
	int	ret;

	i = 0;
	if (n >= 16)
	{
		ret = ft_puthex(n / 16, base);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar(base[n % 16]);
	if (ret == -1)
		return (-1);
	return (i + ret);
}
