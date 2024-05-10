#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	printer(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len += ft_putchar('%');
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 'x')
		len += ft_printhex(va_arg(args, unsigned int), 'a');
	if (c == 'X')
		len += ft_printhex(va_arg(args, unsigned int), 'A');
	if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long));
	if (c == 'u')
		len += ft_printlong(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int	len;
	va_list	args;
	va_start(args, str);

	len = 0;
	while (*str)
	{
		if (str[0] != '%')
		{
			ft_putchar((char)str[0]);
			str++;
			len++;
		}
		if (str[0] == '%' && str[1] != '\0')
		{
			len += printer(str[1], args);
			str += 2;
		}
	}
	va_end(args);
	return (len);
}
