#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>

int	printer(char c, va_list args);
int	ft_printf(const char *str, ...);
int	countsize(int n, int base);
char	*vazio(void);
char	*ft_itoa(int n);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
char	*ft_puthexa(unsigned int n, int base);
void printptr(unsigned long ptr, int *len);
int	ft_putptr(unsigned long ptr);
int	ft_printhex(unsigned int n, int base);
int	ft_printlong(unsigned int nb);
int	uncountsize(unsigned int n, int base);
#endif