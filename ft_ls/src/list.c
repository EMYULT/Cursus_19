/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:50:58 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/06/13 17:14:27 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

t_list_ls	*lst_swap(t_list_ls *p1, t_list_ls *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

void print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
		return;
	while(mylist != NULL)
	{
		ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
		mylist = mylist->next;
	}
}

t_list_ls *reverse_list(t_list_ls *mylist)
{
	t_list_ls *prev;
	t_list_ls *current;
	t_list_ls *next;

	prev = NULL;
	next = NULL;
	current = mylist;
	while (current != NULL)
	{
			next  = current->next;
			current->next = prev;
			prev = current;
			current = next;
	}
	mylist = prev;
	return (mylist);
}

t_list_ls *add_link_front(t_list_ls *mylist, char *str, b_arg *arg)
{
	t_list_ls	*tmp;
	struct stat fs;
	char		*tmp2;


	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		if (arg->is_l == 1)
		{
			tmp2= ft_strjoin(arg->path, tmp->file_name);
			if (lstat(tmp2, &fs) < 0)
			{
				ft_printf("error file doesn not exit recursive ");
				return(NULL);
			}
			tmp->date = fs.st_mtime;
		}
		if (arg->is_t == 1 && arg->is_l != 1)
		{
			tmp2= ft_strjoin(arg->path, tmp->file_name);
			if (lstat(tmp2, &fs) < 0)
			{
				ft_printf("error file doesn not exit recursive ");
				return(NULL);
			}
			tmp->date = fs.st_mtime;
		}
		tmp->next = mylist;
	}
	else
		return (NULL);
	return (tmp);
}

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

t_list_ls *add_link_front_dir(t_list_ls *mylistdir, char *str, b_arg *arg)
{
	t_list_ls	*tmp;
	struct stat 	fs;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		if (lstat(str, &fs) < 0)
		{
			ft_printf("error file doesn not exit recursive ");
			return(NULL);
		}
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
				mylist = add_link_front(mylist, tmp, arg);
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
			mylist = add_link_front(mylist, tmp, arg);
		}
	}
	closedir(d);
	return (mylist);
}
