/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:24:58 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:37 by sloubiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		written;
	int		temp;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	written = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			temp = check_args(s[++i], ap);
			if (temp >= 0)
				i++;
			written += temp;
		}
		else
			written += write(1, &s[i++], 1);
	}
	va_end(ap);
	return (written);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		if (ft_putchar(s[i++]) < 1)
			return (-1);
	return (i);
}

int	print_addr(void *p)
{
	int	total;

	if (!p)
		return (ft_putstr("(nil)"));
	total = ft_putstr("0x");
	total += print_hex_nbr((unsigned long)p, 0);
	return (total);
}

int	check_args(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (print_addr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (print_dec_nbr(va_arg(ap, int)));
	else if (c == 'u')
		return (print_undec_nbr(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (print_hex_nbr(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (print_hex_nbr(va_arg(ap, unsigned int), 1));
	return (-1);
}

/*#include <stdio.h>

int	main(void)
{
	char var = 's';
	char *ptr = &var;
	char *str = "str";
	unsigned int us_int = 4294967295;
	int printf_return;
	int ft_printf_return;
	ft_printf_return = 0;
	printf_return = 0;
	str = 0;
	ptr = 0;
	 printf_return = printf("issprintf :dsds %p %i %s 
	 %d %u %x %X %%\n", ptr, 4, "test",
	 	2147483647, us_int, us_int, us_int);
	 ft_printf_return = ft_printf("ft_printf :dsds %p %i %s 
	 %d %u %x %X %%\n", ptr, 4, "test",
	 	2147483647, us_int, us_int, us_int);
	//printf_return = printf("%p", 16);
	//ft_printf_return = ft_printf("%p", 16);
	printf("\n");
	printf("printf return : %d\n", printf_return);
	printf("ft_printf return : %d\n", ft_printf_return);
}*/