/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 08:05:11 by tjuzen            #+#    #+#             */
/*   Updated: 2019/04/01 08:05:14 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		float_sign(t_arg *arg)
{
	if (arg->flag2 == 1)
		ft_putchar_ret_count('-', arg);
	if (arg->is_plus == 1 && arg->flag2 != 1)
		ft_putchar_ret_count('+', arg);
}

long		convert_my_precision(t_arg *arg)
{
	long j;
	long precision;

	j = 1;
	precision = arg->no_precision == 1 ? 6 : arg->precision;
	while (precision != 0)
	{
		j *= 10;
		precision--;
	}
	return (j);
}

void		ft_putchar_ret(char c, t_arg *arg)
{
	write(1, &c, 1);
	arg->ret += 1;
}
