/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 06:36:58 by tjuzen            #+#    #+#             */
/*   Updated: 2019/04/01 06:37:01 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long double	is_float_neg(long double i, t_arg *arg)
{
	if (arg->is_space == 1 && i >= 0 && arg->is_plus == 0)
		ft_putchar_ret_count(' ', arg);
	if (i <= 0)
	{
		i *= -1;
		arg->flag2 = 1;
	}
	return (i);
}

void		float_no_decimal(t_arg *arg, int flag)
{
	int j;

	j = -1;
	if (arg->is_hashtag == 1 && flag != 1)
		ft_putchar_ret_count('.', arg);
	if (arg->flag1 == 1)
		arg->count += 1;
	if (arg->is_minus == 1)
	{
		if (arg->width > arg->count && arg->flag666 != 1)
			while (++j < arg->width - arg->count)
				ft_putchar_ret(' ', arg);
	}
}

void		ft_floatnm(t_arg *arg, long double i)
{
	unsigned long long	avant;
	int					j;

	j = -1;
	arg->is_minus = 1;
	arg->flag666 = 1;
	if (arg->is_zero == 1)
		float_sign(arg);
	if (arg->width > arg->count)
		while (++j < arg->width - arg->count)
			arg->is_zero == 1 ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	i = is_float_neg(i, arg);
	avant = (signed long int)i;
	if (arg->is_zero != 1)
		float_sign(arg);
	float_round(arg, i);
	if (arg->precision == 0 && arg->no_precision == 0)
	{
		float_no_decimal(arg, 0);
		return ;
	}
	float_no_decimal(arg, 1);
}

void		float_round(t_arg *arg, long double i)
{
	long double	float_part;
	long double	max;
	long		j;
	char		*tmp;

	j = convert_my_precision(arg);
	max = i;
	float_part = i - (unsigned long long)max + 1;
	float_part *= j;
	if ((float_part - (unsigned long long)float_part) >= 0.5)
		float_part++;
	if ((float_part / j) > 2)
	{
		max++;
		arg->count -= 1;
		arg->flag1 = 1;
	}
	ft_putnbr_unsigned(max, arg);
	if (arg->precision == 0 && arg->no_precision == 0)
		return ;
	ft_putchar_ret_count('.', arg);
	if (!(tmp = ft_itoa_unsigned(float_part)))
		return ;
	ft_putstr_ret_count(tmp + 1, arg);
	free(tmp);
}

void		ft_float(t_arg *arg, long double i)
{
	i = is_float_neg(i, arg);
	float_sign(arg);
	float_round(arg, i);
	if (arg->precision == 0 && arg->no_precision == 0)
	{
		float_no_decimal(arg, 0);
		return ;
	}
	float_no_decimal(arg, 1);
}
