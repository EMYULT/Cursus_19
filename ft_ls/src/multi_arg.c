/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:10:14 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/08/06 18:29:14 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*fill_file(int i, int argc, char **argv, t_arg_ls *arg)
{
	struct stat	fs;
	char		*tmp;
	t_list_ls	*mylistfile;
	DIR			*d;

	mylistfile = NULL;
	while (i < argc)
	{
		if (lstat(argv[i], &fs) < 0)
			ft_printf("ls: %s: No such file or directory\n", argv[i]);
		else
		{
			if (!(d = opendir(argv[i])))
			{
				if (!(tmp = ft_strdup(argv[i])))
					return (NULL);
				mylistfile = add_link_front(mylistfile, tmp, arg);
				closedir(d);
			}
		}
		i++;
	}
	return (mylistfile);
}

t_list_ls	*fill_dir(int i, int argc, char **argv)
{
	DIR			*d;
	char		*tmp;
	t_list_ls	*mylistdir;

	mylistdir = NULL;
	while (i < argc)
	{
		if ((d = opendir(argv[i])))
		{
			if (!(tmp = ft_strdup(argv[i])))
				return (NULL);
			mylistdir = add_link_front_dir(mylistdir, tmp);
			closedir(d);
		}
		i++;
	}
	return (mylistdir);
}

void		display_my_files(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = check_sort(mylist, arg);
	if (mylist != NULL)
	{
		if (arg->is_l != 1)
			print_list(mylist);
		else
			print_full_list(mylist, arg, 1);
		if (mylist != NULL)
			arg->file_printed = 1;
	}
}

void		display_my_dir(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = check_sort(mylist, arg);
	if (arg->file_printed && mylist)
		ft_printf("\n");
	while (mylist != NULL)
	{
		check_path(mylist->file_name, arg);
		if (arg->flag_mutiple_folders == 1)
			ft_printf("%s:\n", mylist->file_name);
		handle_arg(arg);
		if (mylist->next)
			ft_printf("\n");
		mylist = mylist->next;
	}
}
