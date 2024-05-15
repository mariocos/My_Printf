/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p_u_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:13:38 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/15 15:37:23 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_print_long(unsigned int nb)
{
	int		len;
	char	*str;

	if (nb == 0)
		return (ft_putchar('0'));
	len = un_countsize(nb, 10);
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

int	ft_put_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	else
	{
		len += ft_putstr("0x");
		print_ptr(ptr, &len);
	}
	return (len);
}

void print_ptr(unsigned long ptr, int *len)
{
	if (ptr >= 16)
	{
		print_ptr(ptr / 16, len);
		print_ptr(ptr % 16, len);
	}
	else
		*len += ft_putchar("0123456789abcdef"[ptr % 16]);
}
