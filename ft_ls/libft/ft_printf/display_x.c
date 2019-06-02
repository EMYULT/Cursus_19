/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:53:36 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:53:37 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	display_x_minus(t_arg *arg, char *str, unsigned long long c)
{
	int i;

	i = -1;
	if (arg->specifier == 'x')
		while (str[++i])
			str[i] = ft_tolower(str[i]);
	i = -1;
	if (arg->is_space == 1 && arg->width == 0)
		ft_putchar_ret(' ', arg);
	if (arg->is_hashtag == 1 && c != 0 && arg->precision >= (int)ft_strlen(str))
	{
		if (arg->specifier == 'x')
			ft_putstr_ret("0x", arg);
		else if (arg->specifier == 'X')
			ft_putstr_ret("0X", arg);
	}
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
}

void	ft_hexm(char *str, t_arg *arg, unsigned long long c)
{
	int i;

	i = -1;
	display_x_minus(arg, str, c);
	if (arg->is_hashtag == 1 && c != 0 && arg->precision < (int)ft_strlen(str))
	{
		if (arg->specifier == 'x')
			ft_putstr_ret("0x", arg);
		else if (arg->specifier == 'X')
			ft_putstr_ret("0X", arg);
	}
	if (c == 0 && arg->no_precision == 0 &&
		arg->precision < (int)ft_strlen(str))
	{
		if (arg->width > (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	}
	else
		ft_putstr_ret(str, arg);
	if (arg->width > arg->precision || arg->width > (int)ft_strlen(str))
	{
		if (arg->is_hashtag == 1 && c != 0)
			i += 2;
		precision_m(str, arg, i);
	}
}

void	display_hex(t_arg *arg, unsigned long long c, char *str)
{
	int i;

	i = -1;
	if (arg->specifier == 'x')
		while (str[++i])
			str[i] = ft_tolower(str[i]);
	i = -1;
	if (arg->is_space == 1 && arg->width != 0 && c != 0)
		ft_putchar_ret(' ', arg);
	if (arg->is_hashtag == 1 && c != 0 &&
		((arg->precision > (int)ft_strlen(str) || arg->is_zero == 1)))
	{
		arg->flag1 = 1;
		if (arg->specifier == 'x')
			ft_putstr_ret("0x", arg);
		else if (arg->specifier == 'X')
			ft_putstr_ret("0X", arg);
	}
	if (arg->width > arg->precision || arg->width > (int)ft_strlen(str))
	{
		if (arg->is_hashtag == 1 && c != 0)
			i += 2;
		precision_no_m(str, arg, i);
	}
}

void	ft_hexnm(char *str, t_arg *arg, unsigned long long c)
{
	int i;

	i = -1;
	display_hex(arg, c, str);
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	if (arg->is_hashtag == 1 && c != 0 && arg->flag1 != 1)
	{
		if (arg->specifier == 'x')
			ft_putstr_ret("0x", arg);
		else if (arg->specifier == 'X')
			ft_putstr_ret("0X", arg);
	}
	if (c == 0 && arg->no_precision == 0 &&
		arg->precision < (int)ft_strlen(str))
	{
		if (arg->width > (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	}
	else
		ft_putstr_ret(str, arg);
}
