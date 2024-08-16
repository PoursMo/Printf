#include "ft_printf.h"

static void	show_pointer(va_list lst_ptr, int *count)
{
	unsigned long	address;

	address = (unsigned long)va_arg(lst_ptr, void *);
	if (address)
	{
		*count += ft_putstr("0x");
		*count += ft_putnbr_base(address, "0123456789abcdef");
	}
	else
		*count += ft_putstr("(nil)");
}

static void	call_func(char arg, va_list lst_ptr, int *count)
{
	if (arg == '%')
		*count += ft_putchar(arg) != -1;
	else if (arg == 'd' || arg == 'i')
		*count += ft_putnbr(va_arg(lst_ptr, int));
	else if (arg == 'u')
		*count += ft_putnbr(va_arg(lst_ptr, unsigned int));
	else if (arg == 'x')
		*count += ft_putnbr_base(va_arg(lst_ptr, unsigned int), "0123456789abcdef");
	else if (arg == 'X')
		*count += ft_putnbr_base(va_arg(lst_ptr, unsigned int), "0123456789ABCDEF");
	else if (arg == 's')
		*count += ft_putstr(va_arg(lst_ptr, char *));
	else if (arg == 'c')
		*count += ft_putchar(va_arg(lst_ptr, int)) != -1;
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
			count += ft_putchar(*format) != -1;
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
