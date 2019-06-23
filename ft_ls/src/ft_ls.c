/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/23 17:23:14 by hde-ghel         ###   ########.fr       */
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

// Fonction qui initialise chaque arg de ma struct

void	initialize_arg(b_arg *arg)
{
	ft_bzero(arg, sizeof(b_arg));
	/*
	arg->is_l = 0;
	arg->is_R = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	*/
	arg->path = "./";
}

// Fonction qui parcour argv[1] et qui check les args

int		check_arg(char *str, b_arg *arg, int i, int j)
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
				arg->is_R = 1;
			if (str[i] == 'a')
				arg->is_a = 1;
			if (str[i] == 'r')
				arg->is_r = 1;
			if (str[i] == 't')
				arg->is_t = 1;
			i++;
		}
	}
	return (i == j) ? (1) : (-1);
}

int		check_path(char *str, b_arg *arg)
{
	DIR *d;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	d = opendir(str);
	if (d == NULL)
		return (-1);
	while (str[i])
		i++;
	if (str[i - 1] != '/')
	{
		if (!(arg->path = (char *)malloc(sizeof(char) * i + 2)))
			return (-1);
		while(j < i)
		{
			arg->path[j] = str[j];
			j++;
		}
		arg->path[j] = '/';
		arg->path[j + 1] = '\0';
	}
	else
		arg->path = str;
	closedir(d);
	return (1);
}


int		ft_check_point(char *s)
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
		{
			ft_printf("eeeerror\n");
			return ;
		}
		if (S_ISDIR(fs.st_mode))
		{
			if (ft_check_point(mylist->file_name_path) == 0)
			{
				arg->path = ft_strjoin(mylist->file_name_path, "/");
				ft_printf("\n%s:\n", mylist->file_name_path);
				handle_arg(arg);
			}
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
			print_full_list(mylist);
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

	dir = NULL;
	mylistdir = NULL;
	i = 1;
	flag = 0;
	initialize_arg(arg);
	while (i < argc && argv[i][0] == '-')
	{
		if (check_arg(argv[i], arg, 0, 0) == -1)
		{
			ft_printf("Erreur dans les arguments");
			return (1);
		}
		i++;
	}
	//Condition incorrecte (ex ls ./ ../ ./ft_ls)
	////faire une fonction checkflag avec un while ? (arg != a, l, R, etc print usage)
	flag = (argv[i] && argv[i + 1]) ? 1 : 0;
	if (i == argc)
		handle_arg(arg);
	while (i < argc)
	{
		if (!(d = opendir(argv[i])))
		{
			ft_printf("Erreur ggegregrents");
			return (1);
		}
		if (!(tmp = strdup(argv[i])))
		{
			ft_printf("Erddddments");
			return (1);
		}
		mylistdir = add_link_front_dir(mylistdir, tmp);
		closedir(d);
		i++;
	}
	mylistdir = sort_ascii(mylistdir);
	if (arg->is_t == 1)
		mylistdir = sort_time(mylistdir);
	if (arg->is_r == 1)
		mylistdir = reverse_list(mylistdir);
	while (mylistdir != NULL)
	{
		check_path(mylistdir->file_name, arg);
		if (flag == 1)
			ft_printf("%s:\n", arg->path);
		handle_arg(arg);
		if (mylistdir->next)
			ft_printf("\n");
		mylistdir = mylistdir->next;
	}
	return (0);
}
