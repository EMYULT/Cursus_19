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
//
void	param_l(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	d = opendir(".");
	while(mylist != NULL && (dir = readdir(d)) != NULL)
	{
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
	mylist = reverse_list(mylist);
	print_list(mylist);
}


void	param_a(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	mylist = reverse_list(mylist);
	print_list(mylist);
}

void	param_r(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	print_list(mylist);
}

void	param_t(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	mylist = reverse_list(mylist);
	print_list(mylist);
}

void	no_param(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg)
{
	mylist = push_list(dir, d, mylist, arg);
	mylist = reverse_list(mylist);
	print_list(mylist);
}
