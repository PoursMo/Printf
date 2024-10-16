/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:16:49 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/07 11:03:59 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	loop(uint64_t num, const char *base_to, int baselen, int *count)
{
	if (num > 0)
	{
		loop(num / baselen, base_to, baselen, count);
		*count += ft_putchar(base_to[num % baselen]);
	}
}

int	putulong_base(uint64_t num, const char *base_to)
{
	int	count;
	int	baselen;

	baselen = ft_strlen(base_to);
	if (!base_to || baselen < 2)
		return (-1);
	if (num == 0)
		return (ft_putchar('0'));
	count = 0;
	loop(num, base_to, baselen, &count);
	return (count);
}
