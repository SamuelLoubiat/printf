/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:24:58 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:37 by sloubiat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	check_args(char c, va_list ap);
int	print_hex_nbr(unsigned long nbr, int upper);
int	print_addr(void *p);
int	print_dec_nbr(int nbr);
int	print_undec_nbr(unsigned int nbr);
#endif
