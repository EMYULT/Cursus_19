/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:34:47 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:34:48 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_x_modifier(t_arg *arg, va_list v_arg)
{
	char			*hexadecimal;
	unsigned short	sh;
	unsigned char	ch;
	unsigned long	quotient;

	quotient = 0;
	if (arg->length == 4)
	{
		sh = va_arg(v_arg, unsigned int);
		quotient = sh;
	}
	else if (arg->length == 5)
	{
		ch = va_arg(v_arg, unsigned int);
		quotient = ch;
	}
	if (quotient == 0)
		hexadecimal = ft_strdup("0");
	else
		hexadecimal = ft_itoa_base(quotient, 16);
	if (!hexadecimal)
		return ;
	(arg->is_minus == 1) ? ft_hexm(hexadecimal, arg, quotient) :
	ft_hexnm(hexadecimal, arg, quotient);
	free(hexadecimal);
}

void	handle_hex(va_list v_arg, t_arg *arg)
{
	unsigned long long	quotient;
	char				*hexadecimal;

	if (arg->no_precision != 1)
		arg->is_zero = 0;
	if (arg->length == 0)
		quotient = va_arg(v_arg, unsigned int);
	if (arg->length == 1)
		quotient = va_arg(v_arg, unsigned long);
	if (arg->length == 2)
		quotient = va_arg(v_arg, unsigned long long);
	if (arg->length == 4 || arg->length == 5)
	{
		handle_x_modifier(arg, v_arg);
		return ;
	}
	hexadecimal = (quotient == 0) ? ft_strdup("0") :
	ft_itoa_base_unsigned(quotient, 16);
	if (!hexadecimal)
		return ;
	(arg->is_minus == 1) ? ft_hexm(hexadecimal, arg, quotient) :
	ft_hexnm(hexadecimal, arg, quotient);
	free(hexadecimal);
}

void	handle_integer(va_list v_arg, t_arg *arg)
{
	long long	l;
	char		*str;

	l = 0;
	if (arg->no_precision != 1)
		arg->is_zero = 0;
	if (arg->is_plus == 1)
		arg->is_space = 0;
	if (arg->length == 0)
		l = va_arg(v_arg, int);
	else if (arg->length == 1)
		l = va_arg(v_arg, long);
	else if (arg->length == 2)
		l = va_arg(v_arg, long long);
	else if (arg->length == 4 || arg->length == 5)
	{
		int_modifier(arg, v_arg);
		return ;
	}
	if (!(str = ft_itoa(l)))
		return ;
	if (arg->is_plus == 1 && l < 0)
		arg->is_plus = 0;
	(arg->is_minus == 1) ? ft_intm(str, arg, l) : ft_intnm(str, arg, l, -1);
	free(str);
}

int		int_modifier(t_arg *arg, va_list v_arg)
{
	short	s;
	char	c;
	char	*str;

	if (arg->length == 4)
	{
		s = va_arg(v_arg, int);
		if (!(str = ft_itoa(s)))
			return (-1);
		if (arg->is_plus == 1 && s < 0)
			arg->is_plus = 0;
		(arg->is_minus == 1) ? ft_intm(str, arg, s) : ft_intnm(str, arg, s, -1);
	}
	else
	{
		c = va_arg(v_arg, int);
		if (!(str = ft_itoa(c)))
			return (-1);
		if (arg->is_plus == 1 && c < 0)
			arg->is_plus = 0;
		(arg->is_minus == 1) ? ft_intm(str, arg, c) : ft_intnm(str, arg, c, -1);
	}
	free(str);
	return (0);
}
