/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:13:17 by mariocos          #+#    #+#             */
/*   Updated: 2024/05/15 15:36:57 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		printer(char c, va_list args);
int		ft_printf(const char *str, ...);
int		countsize(int n, int base);
int		un_countsize(unsigned int n, int base);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
char	*ft_puthexa(unsigned int n, int base);
int		ft_put_ptr(unsigned long ptr);
void 	print_ptr(unsigned long ptr, int *len);
int		ft_printhex(unsigned int n, int base);
int		ft_print_long(unsigned int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*empty(void);
#endif
