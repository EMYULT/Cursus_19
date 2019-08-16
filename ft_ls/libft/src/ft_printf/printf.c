/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:50:50 by tjuzen            #+#    #+#             */
/*   Updated: 2019/01/18 12:05:31 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		with_arg(va_list v_arg, t_arg *arg)
{
	int len;

	len = ft_strlen(arg->args) + 1;
	check_spec(arg, v_arg);
	if (arg->args)
		free(arg->args);
	return (len);
}

void	initialize(t_arg *arg)
{
	arg->is_minus = 0;
	arg->is_plus = 0;
	arg->is_space = 0;
	arg->is_hashtag = 0;
	arg->is_zero = 0;
	arg->with_arg = 0;
	arg->specifier = 0;
	arg->args = NULL;
	arg->width = 0;
	arg->precision = 0;
	arg->no_precision = 1;
	arg->length = 0;
	arg->flag1 = 0;
	arg->flag2 = 0;
	arg->count = 0;
	arg->flag666 = 0;
}

int		print_to_percent(char *str, int start, t_arg *arg)
{
	char	*tmp;
	int		i;

	i = start;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	if (i != start)
	{
		tmp = ft_strsub(str, start, i - start);
		if (!tmp)
			return (1);
		ft_putstr_ret(tmp, arg);
		free(tmp);
	}
	else
		return (1);
	return (i - start);
}

int		print_input(char *input, va_list v_arg, t_arg *arg, int i)
{
	int len;

	len = (int)ft_strlen(input);
	while (input[i] && i <= len)
	{
		if (input[i + 1] == '\0' && input[i] == '%')
			return (0);
		while (input[i] == '%' && (get_spec(&input[i + 1], arg, 0, v_arg)) == 1)
			i += ((arg->with_arg == 0) ?
			check_spec(arg, v_arg) : with_arg(v_arg, arg));
		if (input[i] == '\0')
			break ;
		i += print_to_percent(input, i, arg);
	}
	return (arg->ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		v_arg;
	t_arg		arg[1];
	char		*str;

	str = (char*)format;
	va_start(v_arg, format);
	arg->ret = 0;
	print_input(str, v_arg, arg, 0);
	va_end(v_arg);
	return (arg->ret);
}
