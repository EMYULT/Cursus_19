/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:55:14 by tjuzen            #+#    #+#             */
/*   Updated: 2019/07/29 13:39:45 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
			ft_printf("\n");
	}
}

void		display_my_dir(t_list_ls *mylist, t_arg_ls *arg)
{
	mylist = check_sort(mylist, arg);
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

int			check_my_options(int i, int argc, char **argv, t_arg_ls *arg)
{
	i = 0;
	while (i < argc && argv[i][0] == '-')
	{
		if (check_arg(argv[i], arg, 0, 0) != -1)
		{
			ft_printf("ls: illegal option -- %c\n",
			argv[i][check_arg(argv[i], arg, 0, 0)]);
			ft_printf("usage: ls [-lraRt] [file ...]\n");
			return (-1);
		}
		i++;
	}
	if (i == argc)
		handle_arg(arg);
	return (i);
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
			}
		}
		i++;
	}
	return (mylistfile);
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

void		initialize_arg(t_arg_ls *arg)
{
	arg->is_l = 0;
	arg->is_rr = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->path = "./";
	arg->totalsize = 0;
	arg->flag_mutiple_folders = 0;
}

int			check_arg(char *str, t_arg_ls *arg, int i, int j)
{
	while (str[j])
		j++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return (str[i + 1]) ? (-1) : (1);
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
	return (i == j) ? (-1) : (i);
}

int			check_path(char *str, t_arg_ls *arg)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] != '/')
	{
		if (!(arg->path = (char *)malloc(sizeof(char) * i + 2)))
			return (-1);
		while (j < i)
		{
			arg->path[j] = str[j];
			j++;
		}
		arg->path[j] = '/';
		arg->path[j + 1] = '\0';
	}
	else
		arg->path = str;
	return (1);
}

int			check_point(char *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (s[len] != '/' && s[len] != '.')
		len--;
	while (s[len] != '/' && s[len] == '.')
	{
		i++;
		len--;
	}
	if (i == 1 || i == 2)
	{
		if ((ft_strlen(s)) - 3 <= len)
			return (1);
	}
	return (0);
}
