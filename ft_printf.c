/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:16:58 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/07 11:11:47 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	show_pointer(va_list lst_ptr, int *count)
{
	uint64_t	address;

	address = (uint64_t)va_arg(lst_ptr, void *);
	if (address)
	{
		*count += ft_putstr("0x");
		*count += putulong_base(address, "0123456789abcdef");
	}
	else
		*count += ft_putstr("0x0");
}

static void	call_func(char arg, va_list lst_ptr, int *count)
{
	if (arg == '%')
		*count += ft_putchar(arg);
	else if (arg == 'd' || arg == 'i')
		*count += ft_putint(va_arg(lst_ptr, int));
	else if (arg == 'u')
		*count += ft_putuint(va_arg(lst_ptr, uint32_t));
	else if (arg == 'x')
		*count += putulong_base(va_arg(lst_ptr, uint32_t), "0123456789abcdef");
	else if (arg == 'X')
		*count += putulong_base(va_arg(lst_ptr, uint32_t), "0123456789ABCDEF");
	else if (arg == 's')
		*count += ft_putstr(va_arg(lst_ptr, char *));
	else if (arg == 'c')
		*count += ft_putchar(va_arg(lst_ptr, int));
	else if (arg == 'p')
		show_pointer(lst_ptr, count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	lst_ptr;

	va_start(lst_ptr, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += ft_putchar(*format);
		else
		{
			call_func(*(format + 1), lst_ptr, &count);
			format++;
		}
		format++;
	}
	va_end(lst_ptr);
	return (count);
}
