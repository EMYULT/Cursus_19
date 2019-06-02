/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:54:25 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:54:27 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	display_sign_minus(char *str, t_arg *arg, long long c, int len)
{
	int i;

	i = -1;
	if (arg->is_space == 1 && c >= 0)
	{
		i += 1;
		(arg->is_minus != 1) ? ft_putchar_ret(' ', arg) : 0;
	}
	if (c < 0)
	{
		if (arg->width >= len && arg->is_zero == 1 && arg->is_minus != 1)
		{
			ft_putchar_ret('-', arg);
			arg->flag1 = 1;
		}
		if (arg->precision >= len)
			i += 1;
	}
	if (arg->width > arg->precision || arg->width > len)
	{
		if (arg->is_plus == 1 && c >= 0 && arg->is_zero == 1
			&& arg->is_minus == 0)
			ft_putchar_ret('+', arg);
		int_precision_no_m(str, arg, i);
	}
}

void	ft_intm(const char *str, t_arg *arg, long long c)
{
	int i;
	int len;

	len = (int)ft_strlen(str);
	i = -1;
	if (arg->is_space == 1 && c >= 0)
		ft_putchar_ret(' ', arg);
	if (arg->is_plus == 1 && c >= 0)
		ft_putchar_ret('+', arg);
	if (c < 0 && arg->flag1 != 1)
	{
		i -= 1;
		ft_putchar_ret('-', arg);
	}
	if (arg->precision >= len)
		while (++i < (arg->precision - len))
			ft_putchar_ret('0', arg);
	put_or_not_i(c, arg, str, i);
	if (arg->is_hashtag == 1 && c == 0 && arg->no_precision == 0
		&& arg->precision - 1 < (int)ft_strlen(str))
		return ;
	display_sign_minus((char *)str, arg, c, len);
}

void	put_or_not_i(long long c, t_arg *arg, const char *str, int i)
{
	if (c == 0 && arg->no_precision == 0 &&
		arg->precision < (int)ft_strlen(str))
	{
		if (arg->is_minus == 0)
		{
			if (arg->precision == 0 && arg->is_hashtag == 1)
				i++;
			else if (arg->width > (int)ft_strlen(str) && arg->is_plus == 0)
				ft_putchar_ret(' ', arg);
			else if (arg->width > (int)ft_strlen(str) && arg->is_plus == 1)
				ft_putchar_ret('+', arg);
		}
		else if (arg->width > (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	}
	else if (arg->is_hashtag == 1 && c == 0 && arg->no_precision == 0
		&& arg->precision - 1 < (int)ft_strlen(str))
		return ;
	else
		ft_putnbr_no_sign(c, arg);
}

void	ft_intnm(const char *str, t_arg *arg, long long c, int i)
{
	int len;

	len = (int)ft_strlen(str);
	display_sign_minus((char *)str, arg, c, len);
	if (arg->is_plus == 1 && c >= 0 && arg->is_zero != 1)
	{
		if (c == 0 && arg->no_precision == 0 &&
			arg->precision < (int)ft_strlen(str) && arg->width >
			(int)ft_strlen(str) && arg->is_plus == 1)
			ft_putchar_ret(' ', arg);
		else
			ft_putchar_ret('+', arg);
	}
	if (arg->is_zero == 1 && arg->is_plus == 1 && arg->width == 0)
		ft_putchar_ret('+', arg);
	if (c < 0 && arg->flag1 != 1)
	{
		i -= 1;
		ft_putchar_ret('-', arg);
	}
	if (arg->precision >= len)
		while (++i < (arg->precision - len))
			ft_putchar_ret('0', arg);
	put_or_not_i(c, arg, str, i);
}
