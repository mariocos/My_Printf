/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:13:27 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/15 15:41:55 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		count;

	count = countsize(n, 10);
	if (n == 0)
		return (empty());
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
