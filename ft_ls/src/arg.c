/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:16:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/02/18 15:16:02 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// Fonctions qui gèrent les param

// Je mets sous forme de string mes fichiers non cachés (!(.)) dans ma liste
// Je parcours ma liste en affichant les str et permissions

void	param_l(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	mylist = sort_list(mylist, arg);
	if (arg->is_r == 1)
		mylist = reverse_list(mylist);
	d = opendir(arg->path);

	ft_printf("Mon path = %s\n", mylist->file_name_path);
	while(mylist != NULL && (dir = readdir(d)) != NULL)
	{
		mylist->file_name_path = ft_strjoin(arg->path, mylist->file_name);
		print_permissions(mylist->file_name, fs);
		print_hardlinks(mylist->file_name, fs);
		print_owner(mylist->file_name, fs);
		print_size(mylist->file_name, fs);
		print_date(mylist->file_name, fs);
		ft_printf("%s\n", mylist->file_name);
		mylist = mylist->next;
	}
	closedir(d);
}

void	param_R(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	mylist = sort_list(mylist, arg);
}

t_list_ls	*params(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg)
{
	struct stat 	fs;

	if (arg->is_l == 1)
		param_l(dir, d, fs, mylist, arg);
	else
	{
		mylist = push_list(dir, d, mylist, arg);
		mylist = sort_list(mylist, arg);
	}
	return (mylist);
}
