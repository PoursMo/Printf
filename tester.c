#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_printf(const char *format, ...);

int main()
{
	printf("printf : %d\n", printf("%p\n", "bite"));
	ft_printf("ft_printf : %d\n", ft_printf("%p\n", "bite"));
}
