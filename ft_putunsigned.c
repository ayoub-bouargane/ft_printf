/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 18:09:37 by aybouarg          #+#    #+#             */
/*   Updated: 2026/11/07 18:09:39 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n > 9)
	{
		ret = ft_putunsigned(n / 10);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret == -1)
		return (-1);
	i += ret;
	return (i);
}
