/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouarg <aybouarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:01:19 by aybouarg          #+#    #+#             */
/*   Updated: 2026/11/07 16:01:21 by aybouarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	i;
	int	ret;

	if (!p)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	if (i == -1)
		return (-1);
	ret = ft_puthex((unsigned long)p, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (i + ret);
}
