/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:39:27 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/14 16:02:59 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		free_struct_arg(t_arg_ls *arg)
{
	if (arg->path)
		ft_strdel(&arg->path);
	return (1);
}

int		free_list_dir(t_list_ls *list, int r)
{
	t_list_ls	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (r);
}

int		free_list(t_list_ls *list, int r)
{
	t_list_ls	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->file_name != NULL)
			ft_strdel(&list->file_name);
		if (list->file_name_path != NULL)
			ft_strdel(&list->file_name_path);
		if (list->pwname != NULL)
			ft_strdel(&list->pwname);
		if (list->grname != NULL)
			ft_strdel(&list->grname);
		if (list->date_month != NULL)
			ft_strdel(&list->date_month);
		if (list->date_day != NULL)
			ft_strdel(&list->date_day);
		if (list->date_hour_year != NULL)
			ft_strdel(&list->date_hour_year);
		//if (list->have_symlink != NULL)
		//	ft_strdel(&list->have_symlink);
		free(list);
		list = tmp;
	}
	return (r);
}

int		check_arg(char *str, t_arg_ls *arg, int i, int j)
{
	while (str[j])
		j++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return (1);
		while (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' ||
		str[i] == 'r' || str[i] == 't' || str[i] == 'n')
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
			if (str[i] == 'n')
			{
				arg->is_l = 1;
				arg->is_n = 1;
			}
			i++;
		}
	}
	return ((i == j) ? (-1) : (i));
}

int		check_options(int i, int argc, char **argv, t_arg_ls *arg)
{
	int		option_pointer;

	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '\0')
			return (i);
		if (argv[i][1] && argv[i][1] == '-' && argv[i][2] == '\0')
			return (i + 1);
		if ((option_pointer = check_arg(argv[i], arg, 0, 0)) != -1)
		{
			ft_printf("ls: illegal option -- %c\n", argv[i][option_pointer]);
			ft_putstr("usage: ls [-lraRt]");
			ft_putstr(" [file ...]\n");
			return (-1);
		}
		i++;
	}
	return (i);
}
