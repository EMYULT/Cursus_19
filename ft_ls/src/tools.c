/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:55:14 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/18 19:22:22 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		free_all(t_list_ls *list_dir, t_arg_ls *arg)
{
	free_list_dir(list_dir, 0);
	if (arg->is_rr == 0)
		free_struct_arg(arg, 1);
	return (1);
}

int		ft_strdel_int(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
	return (-1);
}

int		init_arg(t_arg_ls *arg)
{
	arg->is_l = 0;
	arg->is_rr = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->is_n = 0;
	if (!(arg->path = ft_strdup("./")))
		return (-1);
	arg->totalsize = 0;
	arg->flag_mutiple_folders = 0;
	arg->file_printed = 0;
	arg->is_in_recu = 0;
	arg->malloc_error = 0;
	arg->count = 0;
	arg->perm_denied = 0;
	return (0);
}

void	init_arg_2(t_arg_lsbig *arg)
{
	arg->big_hard = 0;
	arg->big_pw = 0;
	arg->big_gr = 0;
	arg->big_size = 0;
	arg->big_size_maj = 0;
	arg->have_maj_min = 0;
}

int		check_path(char *str, t_arg_ls *arg)
{
	int j;

	j = 0;
	if (!str)
		return (0);
	if (arg->path)
		if (arg->flag_mutiple_folders == 0 || ft_strcmp(arg->path, "./") == 0
		|| (arg->flag_mutiple_folders && arg->is_rr == 0))
			ft_strdel(&arg->path);
	if (ft_strcmp(str, "/") == 0)
	{
		if (!(arg->path = ft_strdup("/")))
			return (-1);
	}
	else
	{
		if (!(arg->path = ft_strjoin(str, "/")))
			return (-1);
	}
	return (0);
}
