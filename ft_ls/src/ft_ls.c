/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/13 17:14:28 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*params(t_list_ls *mylist, b_arg *arg)
{
	DIR				*d;
	struct dirent	*dir;

	mylist = NULL;
	dir = NULL;
	d = NULL;
	mylist = push_list(dir, d, mylist, arg);
	if (mylist != NULL)
		mylist = sort_ascii(mylist);
	else
		return (NULL);
	return (mylist);
}

void		recursive_dir(b_arg *arg, t_list_ls *mylist)
{
	struct stat	fs;
	char		*tmp;

	tmp = arg->path;
	while (mylist != NULL)
	{
		mylist->file_name_path = ft_strjoin(tmp, mylist->file_name);
		if (!mylist->file_name_path)
			return ;
		if (lstat(mylist->file_name_path, &fs) < 0)
			return ;
		if (S_ISDIR(fs.st_mode))
		{
			ft_printf("\n%s", tmp);
			if (arg->coucou != 1)
				ft_printf("/");
			ft_printf("%s:\n", mylist->file_name);
			arg->path = ft_strjoin(mylist->file_name_path, "/");
			arg->totalsize = 0;
			handle_arg(arg);
		}
		mylist = mylist->next;
	}
}

void		handle_arg(b_arg *arg)
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
			print_full_list(mylist, arg);
	}
	if (arg->is_R)
		recursive_dir(arg, mylist);
}

int			main(int argc, char **argv)
{
	b_arg			arg[1];
	int				i;
	int				flag;
	t_list_ls		*mylistdir;
	struct dirent	*dir;
	DIR				*d;
	char 			*tmp;
	struct stat		fs;

	dir = NULL;
	mylistdir = NULL;
	i = 1;
	flag = 0;
	initialize_arg(arg);

	while (i < argc && argv[i][0] == '-')
	{
		if (check_arg(argv[i], arg, 0, 0) != -1)
		{
			ft_printf("ls: illegal option -- %c\nusage: ls [-lraRt] [file ...]\n", argv[i][check_arg(argv[i], arg, 0, 0)]);
			return (1);
		}
		i++;
	}

	flag = (argv[i] && argv[i + 1]) ? 1 : 0;
	if (i == argc)
		handle_arg(arg);

	t_list_ls *display_files;
	display_files = NULL;

	while (i < argc)
	{
		if ((d = opendir(argv[i])))
		{
			if (!(tmp = strdup(argv[i])))
				return (1);
			mylistdir = add_link_front_dir(mylistdir, tmp);
			closedir(d);
		}
		else if (lstat(argv[i], &fs) < 0)
		{
			ft_printf("ls: %s: No such file or directory\n", argv[i]);
			return (1);
		}
		else
		{
			if (!(tmp = strdup(argv[i])))
				return (1);
			display_files = add_link_front_dir(display_files, tmp);
		}
		i++;
	}

	mylistdir = check_sort(mylistdir, arg);
	display_files = check_sort(display_files, arg);

	if (display_files != NULL)
	{
		print_list(display_files);
		ft_printf("\n");
	}

	while (mylistdir != NULL)
	{
		check_path(mylistdir->file_name, arg);
		if (flag == 1 && mylistdir->is_dir != -50)
			ft_printf("%s:\n", arg->path);
		handle_arg(arg);
		if (mylistdir->next)
			ft_printf("\n");
		mylistdir = mylistdir->next;
	}
	return (0);
}
