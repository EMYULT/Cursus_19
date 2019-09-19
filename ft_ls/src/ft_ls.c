/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:21:56 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/18 14:01:54 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*params(t_list_ls *mylist, t_arg_ls *arg)
{
	DIR				*d;
	struct dirent	*dir;

	d = NULL;
	dir = NULL;
	mylist = push(mylist, arg, d, dir);
	mylist = sort_ascii(mylist);
	return (mylist);
}

int			handle_arg(t_arg_ls *arg)
{
	t_list_ls		*mylist;

	mylist = NULL;
	mylist = params(mylist, arg);
	if ((mylist == NULL && (arg->malloc_error == 1)))
		return (1);
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
		if (recursive_dir(arg, mylist) == -1)
			return (free_list(mylist, 1));
	}
	return (free_list(mylist, 0));
}

int			multi_arg(int i, int argc, char **argv, t_arg_ls *arg)
{
	t_list_ls		*mylistdir;
	t_list_ls		*mylistfile;

	mylistdir = NULL;
	mylistfile = NULL;
	if (argc - i > 1)
		arg->flag_mutiple_folders = 1;
	if (!(mylistfile = fill_file(i, argc, argv, arg)) && arg->malloc_error)
		return (free_all(mylistdir, arg));
	mylistfile = display_my_files(mylistfile, arg);
	if (!(mylistdir = fill_dir(i - 1, argc, argv, arg)) && arg->malloc_error)
		return (free_all(mylistdir, arg));
	if (!(mylistdir = display_my_dir(mylistdir, arg)) && arg->malloc_error)
		return (free_all(mylistdir, arg));
	free_all(mylistdir, arg);
	return (0);
}

int			main(int argc, char **argv)
{
	t_arg_ls		arg;
	int				i;

	i = 0;
	if (init_arg(&arg) == -1)
		return (1);
	if ((i = check_options(1, argc, argv, &arg)) == -1)
		return (free_struct_arg(&arg, 1));
	if (i == argc)
	{
		i = handle_arg(&arg);
		if (arg.is_rr == 0)
			free_struct_arg(&arg, 1);
		return (i);
	}
	return (multi_arg(i, argc, argv, &arg));
}
