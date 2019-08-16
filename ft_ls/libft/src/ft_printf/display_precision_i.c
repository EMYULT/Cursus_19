/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_precision_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:55:18 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:55:19 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		int_precision_no_m(const char *str, t_arg *arg, int i)
{
	if (arg->precision < (int)ft_strlen(str))
		while (++i + arg->is_plus < arg->width - (int)ft_strlen(str))
			arg->is_zero == 1 && arg->is_minus != 1 ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	else
		while (++i + arg->is_plus < arg->width - arg->precision)
			arg->is_zero == 1 && arg->is_plus == 0 && arg->is_minus != 1 ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	return (i);
}

int		int_precision_m(const char *str, t_arg *arg, int i)
{
	if (arg->precision < (int)ft_strlen(str))
		while (++i + arg->is_plus < arg->width - (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	else
		while (++i + arg->is_plus < arg->width - arg->precision)
			ft_putchar_ret(' ', arg);
	return (i);
}
