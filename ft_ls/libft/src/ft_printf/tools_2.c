/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:28:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/03/28 15:28:03 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_no_sign(long long n, t_arg *arg)
{
	if (n == LONG_MIN)
	{
		ft_putstr_ret("922337203685477580", arg);
		n = 8;
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr_no_sign(n / 10, arg);
		ft_putnbr_no_sign(n % 10, arg);
	}
	else
		ft_putchar_ret(n + '0', arg);
}

void	ft_putnbr_unsigned(unsigned long long n, t_arg *arg)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, arg);
		ft_putnbr_unsigned(n % 10, arg);
	}
	else
		ft_putchar_ret_count(n + '0', arg);
}

void	ft_putchar_ret_count(char c, t_arg *arg)
{
	if (arg->is_minus == 1)
	{
		write(1, &c, 1);
		arg->ret += 1;
	}
	if (arg->flag666 != 1)
		arg->count += 1;
}

void	ft_putstr_ret(char const *s, t_arg *arg)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
	arg->ret += i;
}

void	ft_putstr_ret_count(char const *s, t_arg *arg)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		if (arg->is_minus == 1)
			write(1, s, i);
	}
	if (arg->is_minus == 1)
		arg->ret += i;
	if (arg->flag666 != 1)
		arg->count += i;
}
