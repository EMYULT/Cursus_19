/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:53:28 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/22 12:53:29 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*sort_ascii(t_list_ls *mylist)
{
	if (!mylist)
		return (NULL);
	if (mylist->next && ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
		mylist = lst_swap(mylist, mylist->next);
	mylist->next = sort_ascii(mylist->next);
	if (mylist->next && ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
	{
		mylist = lst_swap(mylist, mylist->next);
		mylist->next = sort_ascii(mylist->next);
	}
	return (mylist);
}

t_list_ls	*sort_time(t_list_ls *mylist)
{
	if (!mylist)
		return (NULL);
	if (mylist->next && (mylist->date < mylist->next->date))
		mylist = lst_swap(mylist, mylist->next);
	mylist->next = sort_time(mylist->next);
	if (mylist->next && (mylist->date < mylist->next->date))
	{
		mylist = lst_swap(mylist, mylist->next);
		mylist->next = sort_time(mylist->next);
	}
	return (mylist);
}

t_list_ls *add_link_front_dir(t_list_ls *mylistdir, char *str)
{
	t_list_ls		*tmp;
	struct stat 	fs;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		if (lstat(str, &fs) < 0)
			return(NULL);
		tmp->date = fs.st_mtime;
		tmp->next = mylistdir;
	}
	else
		return (NULL);
	return (tmp);
}

t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg)
{
	char *tmp;

	if (arg->is_a == 1)
	{
		if (!(d = opendir(arg->path)))
			return (NULL);
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] == '.')
			{
				if (!(tmp = strdup(dir->d_name)))
					return (NULL);
				mylist = add_link_front(mylist, tmp, arg, 1);
			}
		}
		closedir(d);
	}
	if (!(d = opendir(arg->path)))
		return (NULL);
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] != '.')
		{
			if (!(tmp = strdup(dir->d_name)))
				return (NULL);
			mylist = add_link_front(mylist, tmp, arg, 1);
		}
	}
	closedir(d);
	return (mylist);
}

t_list_ls	*lst_swap(t_list_ls *p1, t_list_ls *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}
