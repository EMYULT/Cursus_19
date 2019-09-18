/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:35:53 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/18 13:39:06 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*malloc_error(t_arg_ls *arg)
{
	arg->malloc_error = 1;
	return (NULL);
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

t_list_ls	*add_no_file(t_list_ls *mylist, char *str)
{
	t_list_ls	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	if (!(tmp->file_name = ft_strdup(str)))
		return (NULL);
	tmp->next = mylist;
	return (tmp);
}

void		print_delete(t_list_ls *mylistfile)
{
	t_list_ls	*tmp;

	mylistfile = sort_ascii(mylistfile);
	tmp = mylistfile;
	while (tmp != NULL)
	{
		ft_printf("ls: %s: No such file or directory\n", tmp->file_name);
		tmp = tmp->next;
	}
	while (mylistfile)
	{
		tmp = mylistfile->next;
		ft_strdel(&mylistfile->file_name);
		free(mylistfile);
		mylistfile = tmp;
	}
}

int			no_file(char **argv, int i, int argc)
{
	t_list_ls	*mylistfile;
	struct stat	fs;
	int			count;

	count = 0;
	mylistfile = NULL;
	while (i < argc)
	{
		if (lstat(argv[i], &fs) < 0)
		{
			if (!(mylistfile = add_no_file(mylistfile, argv[i])))
				return (-1);
			count++;
		}
		i++;
	}
	print_delete(mylistfile);
	return (count);
}
