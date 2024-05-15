/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:19:22 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:07 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

char	*empty(void)
{
	char	*ret;

	ret = malloc(2);
	if (ret == NULL)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

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

int	un_countsize(unsigned int n, int base)
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

