/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:40:57 by tjuzen            #+#    #+#             */
/*   Updated: 2019/01/21 16:40:59 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_point(va_list v_arg, t_arg *arg)
{
	long	ptr;
	char	*base;
	int		i;
	int		len;

	i = -1;
	ptr = va_arg(v_arg, long);
	if (!(base = ft_itoa_base(ptr, 16)))
		return ;
	len = (int)ft_strlen(base);
	while (++i < len)
		base[i] = ft_tolower(base[i]);
	(arg->is_minus == 1) ? avec_minus(base, arg) : sans_minus(base, arg);
	free(base);
}

void	handle_float(va_list v_arg, t_arg *arg)
{
	long double	i;
	char		*str;

	i = (arg->length == 0) ? va_arg(v_arg, double) : va_arg(v_arg, long double);
	if (!(str = ft_itoa(i)))
		return ;
	if (i < 0)
	{
		ft_float(arg, i);
		if (arg->is_minus == 0)
			ft_floatnm(arg, i);
	}
	else
	{
		ft_float(arg, i);
		if (arg->is_minus == 0)
			ft_floatnm(arg, i);
	}
	free(str);
}

void	handle_char(va_list v_arg, t_arg *arg)
{
	int c;

	c = (va_arg(v_arg, int));
	(arg->is_minus == 1) ? ft_chrmin(c, arg) : ft_chrnmin(c, arg);
}

void	handle_string(va_list v_arg, t_arg *arg)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(v_arg, char*);
	if (str == NULL)
		str = "(null)";
	(arg->is_minus == 1) ? ft_strm(str, arg) : ft_strnm(str, arg);
}
