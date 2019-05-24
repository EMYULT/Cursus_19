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

#include "ft_ls.h"

// Fonctions qui gèrent les param

// Je mets sous forme de string mes fichiers non cachés (!(.)) dans ma liste
// Je parcours ma liste en affichant les str et permissions

void	param_l(struct dirent *dir, DIR *d, struct stat fs, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.')
			mylist = push_back_list(mylist, dir->d_name);
	closedir(d);

	d = opendir(".");
	while(mylist != NULL && (dir = readdir(d)) != NULL)
	{
		print_permissions(mylist->value, fs);
		print_hardlinks(mylist->value, fs);
		print_owner(mylist->value, fs);
		print_size(mylist->value, fs);
		print_date(mylist->value, fs);
		ft_printf("%s\n", mylist->value);
		mylist = mylist->next;
	}
	closedir(d);
}

void	param_R(struct dirent *dir, DIR *d, struct stat fs, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.')
			mylist = push_back_list(mylist, dir->d_name);
	closedir(d);
	print_list(mylist);
}

void	param_a(struct dirent *dir, DIR *d, struct stat fs, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		ft_printf("%s\n", dir->d_name);
	closedir(d);
	ft_printf("\n");
}

void	param_r(struct dirent *dir, DIR *d, struct stat fs, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.')
			mylist = push_front_list(mylist, dir->d_name);
	closedir(d);
	print_list(mylist);
}

void	param_t(struct dirent *dir, DIR *d, struct stat fs, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.')
			mylist = push_back_list(mylist, dir->d_name);
	closedir(d);
	print_list(mylist);
}

void	no_param(struct dirent *dir, DIR *d, List mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.')
			mylist = push_back_list(mylist, dir->d_name);
	closedir(d);
	print_list(mylist);
}
