/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:16:45 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/07 10:42:02 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_putint(int nbr)
{
	int	count;

	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += ft_putchar('-');
	}
	if (nbr > 9)
		count += ft_putint(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	ft_putuint(uint32_t nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putint(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
