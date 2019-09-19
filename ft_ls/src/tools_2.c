/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:39:27 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/19 11:44:08 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		free_struct_arg(t_arg_ls *arg, int ret)
{
	if (arg->path)
		ft_strdel(&arg->path);
	return (ret);
}

void	check_check(t_arg_ls *arg, char stri)
{
	if (stri == 'l')
		arg->is_l = 1;
	if (stri == 'R')
		arg->is_rr = 1;
	if (stri == 'a')
		arg->is_a = 1;
	if (stri == 'r')
		arg->is_r = 1;
	if (stri == 't')
		arg->is_t = 1;
	if (stri == 'n')
	{
		arg->is_l = 1;
		arg->is_n = 1;
	}
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
			check_check(arg, str[i]);
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
			ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
			ft_putstr(" [file ...]\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

int		recursive_dir(t_arg_ls *arg, t_list_ls *mylist)
{
	struct stat		fs;
	char			*tmp;

	tmp = arg->path;
	while (mylist != NULL)
	{
		if (!(mylist->file_name_path = ft_strjoin(tmp, mylist->file_name)))
			return (-1);
		if (lstat(mylist->file_name_path, &fs) < 0)
			return (0);
		if (S_ISDIR(fs.st_mode) && ft_strcmp(mylist->file_name, ".") &&
				ft_strcmp(mylist->file_name, ".."))
		{
			if (!(arg->path = ft_strjoin(mylist->file_name_path, "/")))
				return (-1);
			ft_printf("\n%s:\n", mylist->file_name_path);
			arg->totalsize = 0;
			if (handle_arg(arg) == 1)
				return (ft_strdel_int(&tmp));
		}
		mylist = mylist->next;
	}
	ft_strdel(&tmp);
	return (0);
}
