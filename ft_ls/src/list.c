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

void print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
		return;
	while(mylist != NULL)
	{
		ft_printf("%s\n", mylist->file_name);
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

t_list_ls *add_link_front(t_list_ls *mylist, char *str)
{
	t_list_ls *tmp;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		tmp->next = mylist;
	}
	else
		return (NULL);
	return (tmp);
}

t_list_ls	*sort_list(t_list_ls *mylist, b_arg *arg)
{
	t_list_ls	*curseur1;
	t_list_ls	*curseur2;
	char		*tmp;

	curseur1 = mylist;
	curseur2 = mylist->next;
	while (curseur2 != NULL)
	{
		if (ft_strcmp(curseur1->file_name, curseur2->file_name) > 0)
		{
			tmp = curseur1->file_name;
			curseur1->file_name = curseur2->file_name;
			curseur2->file_name = tmp;
			curseur1 = mylist;
			curseur2 = mylist->next;
		}
		else
		{
			curseur1 = curseur1->next;
			curseur2 = curseur2->next;
		}
	}
	return (mylist);
}
/*

mylist->file_name_path = ft_strjoin(arg->path, mylist->file_name);

*/
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
				mylist = add_link_front(mylist, tmp);
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
			mylist = add_link_front(mylist, tmp);
		}
	}
	closedir(d);
	return (mylist);
}
