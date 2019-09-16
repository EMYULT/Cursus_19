/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:10:14 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/16 15:23:17 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls *add_no_file(t_list_ls *mylist, char *str)
{
	t_list_ls	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	if (!(tmp->file_name = ft_strdup(str)))
		return (NULL);
	tmp->next = mylist;
	return (tmp);
}

int		no_file(char **argv, int i, int argc) //in function
{
	t_list_ls	*mylistfile;
	t_list_ls	*tmp;
	struct stat	fs;
	int count = 0;

	mylistfile = NULL;
	while (i < argc)
	{
		if (lstat(argv[i], &fs) < 0)
		{
			if (!(mylistfile = add_no_file(mylistfile, argv[i])))
				return (-1);
			count++;
		}
		i++;
	}
	mylistfile = sort_ascii(mylistfile);
	tmp = mylistfile;
	while (tmp != NULL)
	{
		ft_printf("ls: %s: No such file or directory\n", tmp->file_name);
		tmp = tmp->next;
	}
	while (mylistfile)
	{
		tmp = mylistfile->next;
		ft_strdel(&mylistfile->file_name);
		free(mylistfile);
		mylistfile = tmp;
	}
	return (count);
}

t_list_ls *file_error(t_arg_ls *arg)
{
	arg->malloc_error = 1;
	return (NULL);
}

t_list_ls	*fill_file(int i, int argc, char **argv, t_arg_ls *arg)
{
	struct stat	fs;
	t_list_ls	*mylistfile;
	int count;
	int diff = i;

	mylistfile = NULL;
	if ((count = no_file(argv, i, argc)) == -1)
		return (NULL);
	while (i < argc)
	{
		if (lstat(argv[i], &fs) == 0)
		{
			if (S_ISREG(fs.st_mode))
			{
				if (!(mylistfile = add_link_front(mylistfile, argv[i], arg)))
					return file_error(arg);
				count++;
			}
			if (S_ISLNK(fs.st_mode))
				if (arg->is_l == 1)
				{
					if (!(mylistfile = add_link_front(mylistfile, argv[i], arg)))
						return (NULL);
					count++;
				}
		}
		i++;
	}
	if (i - diff == count)
		ft_strdel(&arg->path);
	arg->totalsize = 0;
	return (mylistfile);
}

t_list_ls	*fill_dir(int i, int argc, char **argv, t_arg_ls *arg)
{
	DIR			*d;
	t_list_ls	*mylistdir;
	struct stat	fs;
	int			check_last_arg;

	mylistdir = NULL;
	check_last_arg = 0;
	while (i < argc)
	{
		if (lstat(argv[i], &fs) == 0)
		{
			if (S_ISDIR(fs.st_mode) && (d = opendir(argv[i])))
			{
				closedir(d);
				mylistdir = add_link_front_dir(mylistdir, argv[i]);
			}
			else if (S_ISLNK(fs.st_mode))
			{
				if (arg->is_l != 1)
					mylistdir = add_link_front_dir(mylistdir, argv[i]);
			}
			else
			{
				if (i + 1 == argc)
					check_last_arg = 1;
				if ((S_ISDIR(fs.st_mode)))
					permission_denied(argv[i], arg, check_last_arg);
			}
		}
		i++;
	}
	return (mylistdir);
}

t_list_ls	*check_sort(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = sort_ascii(mylist);
	if (arg->is_t == 1)
		mylist = sort_time(mylist);
	if (arg->is_r == 1)
		mylist = reverse_list(mylist);
	return (mylist);
}

t_list_ls		*display_my_files(t_list_ls *mylist, t_arg_ls *arg)
{
	t_list_ls *tmp;

	if (!mylist)
		return (NULL);
	tmp = mylist;
	tmp = check_sort(tmp, arg);
	if (arg->file_printed && tmp)
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

t_list_ls			*display_my_dir(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = check_sort(mylist, arg);
	t_list_ls *tmp;

	tmp = mylist;

	if (arg->file_printed && tmp)
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
