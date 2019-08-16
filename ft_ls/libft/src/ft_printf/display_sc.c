/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:57:53 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:57:54 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_chrmin(int c, t_arg *arg)
{
	int i;

	i = -1;
	if (1 > arg->precision && arg->precision != 0)
		while (++i < arg->precision)
			ft_putchar_ret(c, arg);
	else
		ft_putchar_ret(c, arg);
	i = -1;
	if (arg->width > 1)
		while (++i < arg->width - ((arg->precision != 0) ? 1 : 1))
			ft_putchar_ret(' ', arg);
}

void	ft_chrnmin(int c, t_arg *arg)
{
	int i;

	i = -1;
	if (arg->width > 1)
		while (++i < arg->width - ((arg->precision != 0) ? arg->precision : 1))
			ft_putchar_ret(' ', arg);
	i = -1;
	if (arg->precision != 0 && 1 > arg->precision)
		while (++i < arg->precision)
			ft_putchar_ret(c, arg);
	else
		ft_putchar_ret(c, arg);
}

void	ft_strm(char *str, t_arg *arg)
{
	int i;
	int len;

	len = (int)ft_strlen(str);
	i = -1;
	if (arg->no_precision != 1 && len > arg->precision)
		while (++i < arg->precision)
			ft_putchar_ret(str[i], arg);
	else if (arg->precision == 0 && arg->no_precision == 0)
		i++;
	else
		ft_putstr_ret(str, arg);
	i = -1;
	if (arg->width > arg->precision && arg->no_precision == 0
	&& len > arg->precision)
		while (++i < arg->width - arg->precision)
			ft_putchar_ret(' ', arg);
	else if (arg->width > len)
		while (++i < arg->width - len)
			ft_putchar_ret(' ', arg);
}

void	ft_strnm(char *str, t_arg *arg)
{
	int i;
	int len;

	len = (int)ft_strlen(str);
	i = -1;
	if (arg->width > arg->precision && arg->no_precision == 0
	&& len > arg->precision)
		while (++i < arg->width - arg->precision)
			ft_putchar_ret(' ', arg);
	else if (arg->width > len)
		while (++i < arg->width - len)
			ft_putchar_ret(' ', arg);
	i = -1;
	if (arg->no_precision != 1 && len > arg->precision)
		while (++i < arg->precision)
			ft_putchar_ret(str[i], arg);
	else if (arg->precision == 0 && arg->no_precision == 0)
		i++;
	else
		ft_putstr_ret(str, arg);
}
