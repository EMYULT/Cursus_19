/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_speccc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:34:57 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:34:58 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_octal(va_list v_arg, t_arg *arg)
{
	unsigned long long	di;
	unsigned short		sh;
	unsigned char		ch;

	di = 0;
	if (arg->no_precision != 1)
		arg->is_zero = 0;
	if (arg->length == 0)
		di = va_arg(v_arg, unsigned int);
	else if (arg->length == 1)
		di = va_arg(v_arg, unsigned long);
	else if (arg->length == 2)
		di = va_arg(v_arg, unsigned long long);
	else if (arg->length == 4)
	{
		sh = va_arg(v_arg, int);
		di = sh;
	}
	else if (arg->length == 5)
	{
		ch = va_arg(v_arg, int);
		di = ch;
	}
	octal_modifier(arg, di);
}

void	octal_modifier(t_arg *arg, unsigned long long di)
{
	char *str;

	if (di == 0)
	{
		(arg->is_minus == 1) ? ft_octm("0", arg, 0) : ft_octnm("0", arg, 0, 0);
		return ;
	}
	else if (!(str = ft_itoa_base_unsigned(di, 8)))
		return ;
	(arg->is_minus == 1) ? ft_octm(str, arg, 1) : ft_octnm(str, arg, 1, 0);
	free(str);
}

void	handle_unsigned_long(va_list v_arg, t_arg *arg)
{
	unsigned long long	di;
	unsigned short		sh;
	unsigned char		ch;

	if (arg->no_precision != 1)
		arg->is_zero = 0;
	if (arg->is_plus == 1)
		arg->is_plus = 0;
	if (arg->length == 0)
		di = va_arg(v_arg, unsigned int);
	else if (arg->length == 1)
		di = va_arg(v_arg, unsigned long);
	else if (arg->length == 2)
		di = va_arg(v_arg, unsigned long long);
	else if (arg->length == 4)
	{
		sh = va_arg(v_arg, int);
		di = sh;
	}
	else
	{
		ch = va_arg(v_arg, int);
		di = ch;
	}
	unsigned_modifier(arg, di);
}

void	unsigned_modifier(t_arg *arg, unsigned long long di)
{
	char *str;

	if (di == 0)
	{
		(arg->is_minus == 1) ? ft_unsimm("0", arg, 0) : ft_unsimnm("0", arg, 0);
		return ;
	}
	else if (!(str = ft_itoa_unsigned(di)))
		return ;
	(arg->is_minus == 1) ? ft_unsimm(str, arg, di) : ft_unsimnm(str, arg, di);
	free(str);
}
