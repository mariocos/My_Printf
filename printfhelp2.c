#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	uncountsize(unsigned int n, int base)
{
	long	nb;
	int		space;

	nb = n;
	space = 0;
	while (nb > 0)
	{
		space++;
		nb /= base;
	}
	return (space);
}

int	ft_printlong(unsigned int nb)
{
	int		len;
	char	*str;

	if (nb == 0)
		return (ft_putchar('0'));
	len = uncountsize(nb, 10);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = "0123456789"[nb % 10];
		nb /= 10;
	}
	len = ft_putstr(str);
	free (str);
	return (len);	
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	else
	{
		len += ft_putstr("0x");
		printptr(ptr, &len);
	}
	return (len);
}

void printptr(unsigned long ptr, int *len)
{
	if (ptr >= 16)
	{
		printptr(ptr / 16, len);
		printptr(ptr % 16, len);
	}
	else
		*len += ft_putchar("0123456789abcdef"[ptr % 16]);
}