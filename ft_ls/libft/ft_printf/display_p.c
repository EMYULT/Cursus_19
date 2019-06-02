/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:57:18 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:57:19 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		precision_no_m(const char *str, t_arg *arg, int i)
{
	if (arg->precision < (int)ft_strlen(str))
		while (++i + arg->is_plus < arg->width - (int)ft_strlen(str))
			arg->is_zero == 1 ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	else
		while (++i + arg->is_plus < arg->width - arg->precision)
			arg->is_zero == 1 ?
			ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	return (i);
}

int		precision_m(const char *str, t_arg *arg, int i)
{
	if (arg->precision < (int)ft_strlen(str))
		while (++i + arg->is_plus < arg->width - (int)ft_strlen(str))
			ft_putchar_ret(' ', arg);
	else
		while (++i + arg->is_plus < arg->width - arg->precision)
			ft_putchar_ret(' ', arg);
	return (i);
}

void	avec_minus(char *str, t_arg *arg)
{
	int i;

	str = ft_strjoin("0x", str);
	i = -1;
	if (arg->is_plus == 1)
		ft_putchar_ret('+', arg);
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	ft_putstr_ret(str, arg);
	precision_m(str, arg, i);
	free(str);
}

void	sans_minus(char *str, t_arg *arg)
{
	int i;

	i = -1;
	if (arg->is_zero == 1 && arg->width > (int)ft_strlen(str) + 2)
	{
		ft_putstr_ret("0x", arg);
		i += 2;
	}
	else
		str = ft_strjoin("0x", str);
	precision_no_m(str, arg, i);
	if (arg->is_plus == 1)
		ft_putchar_ret('+', arg);
	if (arg->precision > (int)ft_strlen(str))
		while (++i < (arg->precision - (int)ft_strlen(str)))
			ft_putchar_ret('0', arg);
	ft_putstr_ret(str, arg);
	if (arg->is_zero != 1 || arg->width <= (int)ft_strlen(str) + 2)
		free(str);
}
