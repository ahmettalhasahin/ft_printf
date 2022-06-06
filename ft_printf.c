/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:55:00 by asahin            #+#    #+#             */
/*   Updated: 2022/02/10 12:27:24 by asahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (*str)
	{
		write (1, str, 1);
		count += 1;
		str++;
	}
	return (count);
}

int	ft_putnbr(long double num, int base, int isup)
{
	int	count;
	int	neg;

	count = 1;
	neg = 0;
	if (num < 0)
	{
		write (1, "-", 1);
		num = -num;
		neg = 1;
	}
	if (num > (base - 1))
		count += ft_putnbr(((unsigned long)num / base), base, isup);
	if (isup == 1)
		write(1, &"0123456789ABCDEF"[(unsigned long)num % base], 1);
	else
		write(1, &"0123456789abcdef"[(unsigned long)num % base], 1);
	return (count + neg);
}

int	find_type(char c, va_list list)
{
	int				total_count;

	total_count = 0;
	if (c == 'c')
		total_count += ft_char(va_arg(list, int));
	else if (c == 's')
		total_count += ft_str(va_arg(list, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		total_count += 2;
		total_count += ft_putnbr(va_arg(list, unsigned long), 16, 0);
	}
	else if (c == 'd')
		total_count += ft_putnbr(va_arg(list, int), 10, 0);
	else if (c == 'i')
		total_count += ft_putnbr(va_arg(list, int), 10, 0);
	else if (c == 'u')
		total_count += ft_putnbr(va_arg(list, unsigned int), 10, 0);
	else if (c == 'x')
		total_count += ft_putnbr(va_arg(list, unsigned int), 16, 0);
	else if (c == 'X')
		total_count += ft_putnbr(va_arg(list, unsigned int), 16, 1);
	return (total_count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	va_start(list, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			str++;
			count += ft_char('%');
		}
		else if (*str == '%')
			count += find_type(*(++str), list);
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(list);
	return (count);
}
/*
int main()
{
    int orj;
    int my;
    
    my = ft_printf("deneme: %s ", "asbf");
    orj =   printf("deneme: %s ", "asbf");
    
    printf("%d --- %d", orj, my);
}
int main()
{
    int orj;
    int my;
    
	my = ft_printf(" NULL %s NULL ", NULL);
    orj =   printf(" NULL %s NULL ", NULL);
    
    printf("%d --- %d", orj, my);
}
*/
/*int main()
{
    int orj;
    int my;
    
	my = ft_printf("| %%%% |\n");
    orj =   printf("| %%%% |\n");
    
    printf("%d --- %d", orj, my);
}
*/
