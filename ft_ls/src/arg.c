/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:16:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/13 17:13:02 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*param_l(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg)
{
	struct stat		fs;
	t_list_ls		*tmp;

	mylist = push_list(dir, d, mylist, arg);
	if (mylist != NULL)
	{
		mylist = sort_ascii(mylist);
		if (arg->is_t == 1)
			mylist = sort_time(mylist);
		if (arg->is_r == 1)
			mylist = reverse_list(mylist);
		tmp = mylist;
		d = opendir(arg->path);
		while(mylist != NULL && (dir = readdir(d)) != NULL)
		{
			mylist->file_name_path = ft_strjoin(arg->path, mylist->file_name);
			if (!mylist->file_name_path)
				return(NULL);
			if (lstat(mylist->file_name_path, &fs) < 0)
			{
				ft_printf("error file doesn not exit recursive ");
				return(NULL);
			}
			print_permissions(mylist->file_name, fs);
			print_hardlinks(mylist->file_name, fs);
			print_owner(mylist->file_name, fs);
			print_size(mylist->file_name, fs);
			print_date(mylist->file_name, fs);
			ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
			mylist = mylist->next;
		}
		closedir(d);
		return(tmp);
	}
	else
		return(NULL);
}

t_list_ls	*params(t_list_ls *mylist, b_arg *arg)
{
	DIR				*d;
	struct dirent	*dir;

	mylist = NULL;
	if (arg->is_l == 1)
		mylist = param_l(dir, d, mylist, arg);
	else
	{
		mylist = push_list(dir, d, mylist, arg);
		if (mylist != NULL)
			mylist = sort_ascii(mylist);
		else
			return (NULL);
	}
	return (mylist);
}
