/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/04 17:00:02 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		recursive_dir(t_arg_ls *arg, t_list_ls *mylist)
{
	struct stat		fs;
	char		*tmp;

	tmp = arg->path;
	while (mylist != NULL)
	{
		if (!(mylist->file_name_path = ft_strjoin(tmp, mylist->file_name)))
			return ;
		if (lstat(mylist->file_name_path, &fs) < 0)
			return ;
		if (S_ISDIR(fs.st_mode))
		{
			if (check_point(mylist->file_name_path) == 0)
			{
				if (!(arg->path = ft_strjoin(mylist->file_name_path, "/")))
					return ;
				ft_printf("\n%s:\n", mylist->file_name_path);
				arg->totalsize = 0;
				handle_arg(arg);
			}
		}
		mylist = mylist->next;
	}
	ft_strdel(&tmp);
}

t_list_ls		*params(t_list_ls *mylist, t_arg_ls *arg)
{
	DIR				*d;
	struct dirent	*dir;

	mylist = NULL;
	dir = NULL;
	d = NULL;
	if (!(mylist = push_list(dir, d, mylist, arg)))
		return (NULL);
	mylist = sort_ascii(mylist);
	return (mylist);
}

void		free_list(t_list_ls *list)
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
		if (list->date_string != NULL)
			ft_strdel(&list->date_string);
		if (list->have_symlink != NULL)
			ft_strdel(&list->have_symlink);
		free(list);
		list = tmp;
	}
}

int		free_struct_arg(t_arg_ls *arg)
{
	if (arg->path)
		ft_strdel(&arg->path);
	return (-1);
}

void		handle_arg(t_arg_ls *arg)
{
	t_list_ls		*mylist;

	mylist = NULL;
	mylist = params(mylist, arg);
	if (mylist != NULL)
	{
		if (arg->is_t == 1)
			mylist = sort_time(mylist);
		if (arg->is_r == 1)
			mylist = reverse_list(mylist);
		if (arg->is_l != 1)
			print_list(mylist);
		else
			print_full_list(mylist, arg, 0);
	}
	if (arg->is_rr)
	{
		arg->is_in_recu = 1;
		recursive_dir(arg, mylist);
	}
	free_list(mylist);
}

int			main(int argc, char **argv)
{
	t_arg_ls		arg;
	int				i;
	t_list_ls		*mylistdir;
	t_list_ls		*mylistfile;

	mylistdir = NULL;
	mylistfile = NULL;
	i = 0;
	if (init_arg(&arg) == -1)
		return (1);
	if ((i = check_options(1, argc, argv, &arg)) == -1)
	{
		free_struct_arg(&arg);
		return (1);
	}
	if (i == argc)
		handle_arg(&arg);
	if (argc - i > 1)
		arg.flag_mutiple_folders = 1;
	mylistfile = fill_file(i, argc, argv, &arg);
	display_my_files(mylistfile, &arg);
	mylistdir = fill_dir(i, argc, argv, &arg);
	display_my_dir(mylistdir, &arg);
	return (0);
}
