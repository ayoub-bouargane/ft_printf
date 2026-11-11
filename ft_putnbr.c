/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:46:20 by aybouarg          #+#    #+#             */
/*   Updated: 2026/11/07 17:46:22 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		i += ret;
	}
	if (n > 9)
	{
		ret = ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	return (i + ret);
}
