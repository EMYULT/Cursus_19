/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:53:28 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/12 14:15:14 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*lst_swap(t_list_ls *p1, t_list_ls *p2)
{
	if (!p1 || !p2)
		return (NULL);
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

t_list_ls	*sort_ascii(t_list_ls *mylist)
{
	if (!mylist)
		return (NULL);
	if (mylist->next &&
		ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
		mylist = lst_swap(mylist, mylist->next);
	mylist->next = sort_ascii(mylist->next);
	if (mylist->next &&
		ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
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

t_list_ls	*reverse_list(t_list_ls *mylist)
{
	t_list_ls *prev;
	t_list_ls *current;
	t_list_ls *next;

	prev = NULL;
	next = NULL;
	current = mylist;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	mylist = prev;
	return (mylist);
}
