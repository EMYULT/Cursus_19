/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:40:55 by tjuzen            #+#    #+#             */
/*   Updated: 2019/01/06 12:40:56 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isusable(char c)
{
	if (c != '-' && c != '+' && c != '#' && c != '0' && c != '*' && c != '.'
	&& c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6'
	&& c != '7' && c != '8' && c != '9' && c != ' ' && c != 'h' && c != 'l'
	&& c != 'L')
		return (-1);
	return (1);
}

int		ft_isflag(int c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '#')
		return (1);
	else if (c == '0')
		return (1);
	else
		return (0);
}

int		check_spec(t_arg *arg, va_list v_arg)
{
	if ((arg->specifier == 'i') || (arg->specifier == 'd'))
		handle_integer(v_arg, arg);
	else if (arg->specifier == 'o')
		handle_octal(v_arg, arg);
	else if (arg->specifier == 'u')
		handle_unsigned_long(v_arg, arg);
	else if (arg->specifier == 'x' || arg->specifier == 'X')
		handle_hex(v_arg, arg);
	else if (arg->specifier == 'c')
		handle_char(v_arg, arg);
	if (arg->specifier == 's')
		handle_string(v_arg, arg);
	else if (arg->specifier == 'p')
		handle_point(v_arg, arg);
	else if (arg->specifier == 'f' || arg->specifier == 'F')
		handle_float(v_arg, arg);
	else if (arg->specifier == '%')
		handle_percent(arg, 0);
	return (2);
}

int		get_spec(char *input, t_arg *arg, int i, va_list v_arg)
{
	initialize(arg);
	if (input[i] == 'd' || input[i] == 'i' || input[i] == 'o' ||
	input[i] == 'u' || input[i] == 'x' || input[i] == 'X' || input[i] == 'c'
	|| input[i] == 's' || input[i] == 'p' || input[i] == 'f' ||
	input[i] == '%' || input[i] == 'U' || input[i] == 'C' || input[i] == 'F')
	{
		arg->specifier = input[i];
		return (1);
	}
	while (input[i] != 'd' && input[i] != 'i' && input[i] != 'o' &&
	input[i] != 'u' && input[i] != 'x' && input[i] != 'X' && input[i] != 'c'
	&& input[i] != 's' && input[i] != 'p' && input[i] != 'f' &&
	input[i] != '%' && input[i] && input[i] != 'U' && input[i] != 'C'
	&& input[i] != 'F')
	{
		if (ft_isusable(input[i]) == -1)
			return (i);
		i++;
	}
	arg->with_arg = 1;
	if (!(arg->args = ft_strsub(input, 0, i + 1)))
		return (-1);
	arg->specifier = arg->args[ft_strlen(arg->args) - 1];
	ft_check_arg(arg, v_arg);
	return (1);
}

void	put_or_not(unsigned long long c, t_arg *arg, const char *str, int i)
{
	if (c == 0 && arg->no_precision == 0 &&
		arg->precision < (int)ft_strlen(str))
	{
		if (arg->precision == 0 && arg->is_hashtag == 1)
			i++;
		else if (arg->specifier == 'd' || arg->specifier == 'i')
		{
			if (arg->width > (int)ft_strlen(str) && arg->is_plus == 0)
				ft_putchar_ret(' ', arg);
			else if (arg->width > (int)ft_strlen(str) && arg->is_plus == 1)
				ft_putchar_ret('+', arg);
		}
		else if (arg->width > (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	}
	else if (arg->is_hashtag == 1 && c == 0 && arg->no_precision == 0 &&
		arg->precision - 1 < (int)ft_strlen(str))
	{
		if (arg->is_minus == 1)
			i++;
		else
			return ;
	}
	else
		ft_putstr_ret(str, arg);
}
