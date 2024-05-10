#include <stdlib.h>
#include "ft_printf.h"

int	countsize(int n, int base)
{
	long	nb;
	int		space;

	nb = n;
	space = 0;
	if (nb < 0)
	{
		space++;
		nb *= -1;
	}
	while (nb > 0)
	{
		space++;
		nb /= base;
	}
	return (space);
}

char	*vazio(void)
{
	char	*ret;

	ret = malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		count;

	count = countsize(n, 10);
	if (n == 0)
		return (vazio());
	ret = malloc(count + 1);
	if (ret == NULL)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	ret[count] = '\0';
	while (nb > 0)
	{
		ret[--count] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(n);
	len += ft_putstr(str);
	free (str);
	return (len);
}