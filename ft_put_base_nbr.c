/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:24:58 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:37 by sloubiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setbase(char base[], int nbr, int upper)
{
	int		i;
	char	letter;

	letter = 'a';
	if (upper)
		letter -= 32;
	i = 0;
	while (i < 10 && i < nbr)
	{
		base[i] = i + '0';
		i++;
	}
	while (i < nbr)
		base[i++] = letter++;
	base[i] = 0;
}

int	ft_putnbr(unsigned long nbr, char *base)
{
	unsigned long	size;
	int				count;

	size = 0;
	count = 0;
	while (base[size])
		size++;
	if (nbr >= size)
	{
		count += ft_putnbr(nbr / size, base);
		return (count + ft_putnbr(nbr % size, base));
	}
	return (count + write(1, &base[nbr], 1));
}

int	print_dec_nbr(int nbr)
{
	char	base[11];
	int		count;

	count = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		count = 1;
		write(1, "-", 1);
		nbr = -nbr;
	}
	ft_setbase(base, 10, 0);
	return (count + ft_putnbr(nbr, base));
}

int	print_undec_nbr(unsigned int nbr)
{
	char	base[11];

	ft_setbase(base, 10, 0);
	return (ft_putnbr(nbr, base));
}

int	print_hex_nbr(unsigned long nbr, int upper)
{
	char	base[17];

	ft_setbase(base, 16, upper);
	return (ft_putnbr(nbr, base));
}
