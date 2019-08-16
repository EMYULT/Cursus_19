/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 18:32:36 by tjuzen            #+#    #+#             */
/*   Updated: 2019/01/03 18:32:40 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_arg(t_arg *arg, va_list v_arg)
{
	int i;

	i = 0;
	check_flags(arg, &i);
	check_width(arg, &i, v_arg);
	check_precision(arg, &i, v_arg);
	check_length(arg, &i);
	return (i);
}

int		check_length(t_arg *arg, int *i)
{
	if (arg->args[*i] == 'l')
		arg->length = (arg->args[*i + 1] == 'l') ? 2 : 1;
	else if (arg->args[*i] == 'L')
		arg->length = 3;
	else if (arg->args[*i] == 'h')
		arg->length = (arg->args[*i + 1] == 'h') ? 5 : 4;
	return (0);
}

/*
** l = 1 = (u) long
** ll = 2 = (u) long long
** L = 3 - FLOAT
** h = 4 = (u) short
** hh = 5 = (u) char
*/

int		check_precision(t_arg *arg, int *i, va_list v_arg)
{
	int j;

	j = *i;
	if (arg->args[j] == '.')
	{
		arg->no_precision = 0;
		if (arg->args[j + 1] == '*')
		{
			arg->precision = va_arg(v_arg, int);
			*i += 2;
			return (j);
		}
		*i += 1;
		if (arg->args[j] == '.' && (!(ft_isdigit(arg->args[j + 1]))))
		{
			arg->precision = 0;
			return (j + 1);
		}
		j++;
		while (ft_isdigit(arg->args[j]))
			j++;
		arg->precision = ft_atoi_sub(arg->args, *i, j);
	}
	*i = j;
	return (j);
}

int		check_width(t_arg *arg, int *i, va_list v_arg)
{
	int j;

	j = *i;
	if (arg->args[j] == '*')
	{
		arg->width = va_arg(v_arg, int);
		j++;
	}
	if (ft_isdigit(arg->args[j]))
	{
		while (ft_isdigit(arg->args[j]))
			j++;
		arg->width = ft_atoi_sub(arg->args, *i, j);
	}
	*i = j;
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->is_minus = 1;
	}
	return (j);
}

int		check_flags(t_arg *arg, int *i)
{
	int j;

	j = 0;
	while (ft_isflag(arg->args[j]))
	{
		if (arg->args[j] == '-')
			arg->is_minus = 1;
		if (arg->args[j] == '+')
			arg->is_plus = 1;
		if (arg->args[j] == ' ')
			arg->is_space = 1;
		if (arg->args[j] == '#')
			arg->is_hashtag = 1;
		if (arg->args[j] == '0')
			arg->is_zero = 1;
		j++;
	}
	*i = j;
	return (*i);
}
