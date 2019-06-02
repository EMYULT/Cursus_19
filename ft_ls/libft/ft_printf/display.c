/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:43:10 by tjuzen            #+#    #+#             */
/*   Updated: 2019/02/01 15:43:11 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_flags(t_arg *arg, int i, const char *str)
{
	int j;

	j = -1;
	if (arg->precision < (int)ft_strlen(str))
		while (++j + arg->is_plus + i + 1 < arg->width - (int)ft_strlen(str))
			(arg->is_zero == 1 && arg->is_minus != 1) ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	else
		while (++j + arg->is_plus < arg->width - arg->precision)
			(arg->is_zero == 1 && arg->is_minus != 1) ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
}

void	ft_unsimm(const char *str, t_arg *arg, unsigned long long c)
{
	int i;
	int len;

	len = (int)ft_strlen(str);
	i = -1;
	if (arg->precision > len)
		while (++i < (arg->precision - len))
			ft_putchar_ret('0', arg);
	i = -1;
	if (c == 0 && arg->no_precision == 0 &&
		arg->precision < len)
	{
		if (arg->width > len)
			ft_putchar_ret(' ', arg);
	}
	else
		ft_putstr_ret(str, arg);
	precision_m(str, arg, i);
}

void	ft_unsimnm(const char *str, t_arg *arg, unsigned long long c)
{
	int i;
	int len;

	len = (int)ft_strlen(str);
	i = -1;
	precision_no_m(str, arg, i);
	i = -1;
	if (arg->precision > len)
		while (++i < (arg->precision - len))
			ft_putchar_ret('0', arg);
	if (c == 0 && arg->no_precision == 0 && arg->precision < len)
	{
		if (arg->width > len)
			ft_putchar_ret(' ', arg);
	}
	else
		ft_putstr_ret(str, arg);
}

void	ft_octm(const char *str, t_arg *arg, unsigned long long c)
{
	int i;

	i = -1;
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	if (arg->is_hashtag == 1 && arg->precision - 1 < (int)ft_strlen(str))
		if ((arg->no_precision == 1 && c != 0) || (arg->no_precision == 0 &&
			arg->precision - 1 < (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	put_or_not(c, arg, str, i);
	i = (arg->is_hashtag == 1 && c != 0) ? 0 : -1;
	if (arg->is_hashtag == 1 && c != 0 && arg->no_precision == 0
		&& arg->precision < arg->width && arg->precision > (int)ft_strlen(str))
		i--;
	if (arg->width > arg->precision || arg->width > (int)ft_strlen(str))
		precision_m(str, arg, i);
}

void	ft_octnm(const char *str, t_arg *arg, unsigned long long c, int i)
{
	i = (arg->is_hashtag == 1 && c != 0) ? 0 : -1;
	if (arg->is_hashtag == 1 && c != 0 && arg->no_precision == 0 &&
		arg->precision < arg->width && arg->precision > (int)ft_strlen(str))
		i--;
	if (arg->width > arg->precision || arg->width > (int)ft_strlen(str))
		precision_no_m(str, arg, i);
	i = -1;
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	if (arg->is_hashtag == 1 && arg->precision - 1 < (int)ft_strlen(str))
		if ((arg->no_precision == 1 && c != 0) || (arg->no_precision == 0 &&
			arg->precision - 1 < (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	put_or_not(c, arg, str, i);
}
