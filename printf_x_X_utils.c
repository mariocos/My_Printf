/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x_X_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:13:34 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/15 15:43:35 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libftprintf.h"

char	*ft_puthexa(unsigned int n, int base)
{
	int		count;
	long	nb;
	char	*ret;

	nb = n;
	base -= 10;
	count = un_countsize(nb, 16);
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
