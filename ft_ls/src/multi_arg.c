/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:10:14 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/19 12:55:25 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls		*count_diff(int i, int argc, char **argv, t_arg_ls *arg)
{
	t_list_ls	*mylistfile;
	struct stat	fs;

	mylistfile = NULL;
	while (++i < argc)
	{
		if (lstat(argv[i], &fs) == 0)
		{
			if (S_ISREG(fs.st_mode))
			{
				if (!(mylistfile = add_link_front(mylistfile, argv[i], arg)))
					return (malloc_error(arg));
				arg->count++;
			}
			if (S_ISLNK(fs.st_mode))
				if (arg->is_l == 1)
				{
					if (!(mylistfile = add_link_front(mylistfile,
							argv[i], arg)))
						return (malloc_error(arg));
					arg->count++;
				}
		}
	}
	return (mylistfile);
}

t_list_ls		*fill_file(int i, int argc, char **argv, t_arg_ls *arg)
{
	t_list_ls	*mylistfile;
	int			diff;

	diff = i;
	arg->count = 0;
	if ((no_file(argv, i, argc, arg)) == -1)
		return (malloc_error(arg));
	mylistfile = count_diff(i - 1, argc, argv, arg);
	if (argc - diff == arg->count)
		ft_strdel(&arg->path);
	arg->totalsize = 0;
	return (mylistfile);
}

t_list_ls		*fill_dir(int i, int argc, char **argv, t_arg_ls *arg)
{
	DIR			*d;
	t_list_ls	*mylistdir;
	struct stat	fs;

	mylistdir = NULL;
	while (++i < argc)
	{
		if (lstat(argv[i], &fs) == 0)
		{
			if (S_ISDIR(fs.st_mode) && (d = opendir(argv[i])))
			{
				closedir(d);
				if (!(mylistdir = add_link_front_dir(mylistdir, argv[i])))
					return (malloc_error(arg));
			}
			else if (S_ISLNK(fs.st_mode) && arg->is_l != 1)
			{
				if (!(mylistdir = add_link_front_dir(mylistdir, argv[i])))
					return (malloc_error(arg));
			}
			else if ((S_ISDIR(fs.st_mode)))
				permission_denied(argv[i], arg, argc, i);
		}
	}
	return (mylistdir);
}

t_list_ls		*display_my_files(t_list_ls *mylist, t_arg_ls *arg)
{
	t_list_ls *tmp;

	if (!mylist)
		return (NULL);
	tmp = mylist;
	tmp = check_sort(tmp, arg);
	if (tmp && arg->file_printed)
		ft_printf("\n");
	if (tmp != NULL)
	{
		arg->file_printed = 1;
		if (arg->is_l != 1)
			print_list(tmp);
		else
			print_full_list(tmp, arg, 1);
	}
	free_list_file(tmp, 0);
	return (mylist);
}

t_list_ls		*display_my_dir(t_list_ls *mylist, t_arg_ls *arg)
{
	t_list_ls *tmp;

	mylist = check_sort(mylist, arg);
	tmp = mylist;
	if (tmp && arg->file_printed && arg->perm_denied == 0)
		ft_printf("\n");
	while (tmp != NULL)
	{
		if (check_path(tmp->file_name, arg) == -1)
			return (NULL);
		if (arg->flag_mutiple_folders == 1)
			ft_printf("%s:\n", tmp->file_name);
		if (handle_arg(arg) == 1)
			return (NULL);
		if (tmp->next)
			ft_printf("\n");
		tmp = tmp->next;
	}
	return (mylist);
}
