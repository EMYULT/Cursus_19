/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 14:16:17 by tjuzen            #+#    #+#             */
/*   Updated: 2019/01/05 14:16:19 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		handle_percent(t_arg *arg, int i)
{
	if (arg->is_minus == 1)
	{
		ft_putchar_ret('%', arg);
		if (arg->width > 0)
			while (++i < arg->width)
				arg->is_zero == 1 ?
				ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
	}
	else
	{
		if (arg->width > 0)
			while (++i < arg->width)
				arg->is_zero == 1 ?
				ft_putchar_ret('0', arg) : ft_putchar_ret(' ', arg);
		ft_putchar_ret('%', arg);
	}
	return (0);
}
