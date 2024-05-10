#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
		i += ft_putchar(s[i]);
	return (i);
}

char	*ft_puthexa(unsigned int n, int base)
{
	int		count;
	long	nb;
	char	*ret;

	nb = n;
	base -= 10;
	count = uncountsize(nb, 16);
	ret = malloc (count + 1);
	if (!ret)
		return (NULL);
	ret[count] = '\0';
	while (count-- > 0)
	{
		if (nb % 16 < 10)
			ret[count] = nb % 16 + '0';
		else
			ret[count] = nb % 16 + base;
		nb /= 16;
	}
	return (ret);
}

int	ft_printhex(unsigned int n, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
			len += ft_putchar('0');
	str = ft_puthexa(n, base);
	len += ft_putstr(str);
	free (str);
	return (len);
}
