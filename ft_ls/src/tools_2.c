/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:39:27 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/08/04 17:54:35 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*check_sort(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = sort_ascii(mylist);
	if (arg->is_t == 1)
		mylist = sort_time(mylist);
	if (arg->is_r == 1)
		mylist = reverse_list(mylist);
	return (mylist);
}

int			check_arg(char *str, t_arg_ls *arg, int i, int j)
{
	while (str[j])
		j++;
	//ls - (in rentre pas dedant)
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return ((str[i + 1]) ? -1 : 1);
		while (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' ||
		str[i] == 'r' || str[i] == 't')
		{
			if (str[i] == 'l')
				arg->is_l = 1;
			if (str[i] == 'R')
				arg->is_rr = 1;
			if (str[i] == 'a')
				arg->is_a = 1;
			if (str[i] == 'r')
				arg->is_r = 1;
			if (str[i] == 't')
				arg->is_t = 1;
			i++;
		}
	}
	return ((i == j) ? (-1) : (i));
}

int			check_options(int i, int argc, char **argv, t_arg_ls *arg)
{
	int		option_pointer;

	while (i < argc && argv[i][0] == '-')
	{
		if ((option_pointer = check_arg(argv[i], arg, 0, 0)) != -1)
		{
			ft_printf("ls: illegal option -- %c\n", argv[i][option_pointer]);
			ft_putstr("usage: ls [-lraRt]");
			ft_putstr(" [file ...]\n");
			return (-1);
			// else if (return de check_arg option pointeur)
		}
		i++;
	}
	if (i == argc)
		handle_arg(arg);
	return (i);
}
