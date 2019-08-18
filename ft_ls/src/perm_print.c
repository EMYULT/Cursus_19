/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:51:47 by tjuzen            #+#    #+#             */
/*   Updated: 2019/08/17 15:51:49 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_filename_color(t_list_ls *mylist)
{
	if (mylist->is_dir == 1)
		ft_printf(CYAN"%s\n"DEFAULT_COLOR, mylist->file_name);
	else if (mylist->is_dir == 666)
		ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
	else
		ft_printf(DEFAULT_COLOR"%s\n"DEFAULT_COLOR, mylist->file_name);
}

void		print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
		return;
	while(mylist != NULL)
	{
		print_filename_color(mylist);
		mylist = mylist->next;
	}
}

int			length_int_easy(int x)
{
    if (x >= 1000000000)
		return 10;
    if (x >= 100000000)
		return 9;
    if (x >= 10000000)
		return 8;
    if (x >= 1000000)
		return 7;
    if (x >= 100000)
		return 6;
    if (x >= 10000)
		return 5;
    if (x >= 1000)
		return 4;
    if (x >= 100)
		return 3;
    if (x >= 10)
		return 2;
    return 1;
}

void		print_full_list(t_list_ls *mylist, t_arg_ls *arg, int flag)
{
	int 		big_hard = 0;
	int 		big_pw = 0;
	int 		big_gr = 0;
	int 		big_size = 0;
	int			big_size_maj = 0;
	int			have_maj_min = 0;
	t_list_ls	*tmp = mylist;
	time_t		actualtime;

	actualtime = time(0);
	if (mylist == NULL)
		return;
	if (flag == 0)
	{
		ft_printf("total %lld\n", arg->totalsize);
		arg->totalsize = 0;
	}
	while (tmp != NULL)
	{
		if (length_int_easy(tmp->hardlinks) > big_hard)
			big_hard = length_int_easy(tmp->hardlinks);
		if ((int)ft_strlen(tmp->pwname) > big_pw)
			big_pw = (int)ft_strlen(tmp->pwname);
		if ((int)ft_strlen(tmp->grname) > big_gr)
			big_gr = (int)ft_strlen(tmp->grname);
		if (tmp->minor && tmp->major)
		{
			have_maj_min = 1;
			if (length_int_easy(mylist->major) > big_size_maj)
				big_size_maj = length_int_easy(mylist->major);
			if (length_int_easy(mylist->minor) > big_size)
				big_size = length_int_easy(mylist->minor);
		}
		else if (length_int_easy(tmp->size) > big_size)
			big_size = length_int_easy(tmp->size);
		tmp = tmp->next;
	}
	while(mylist != NULL)
	{
		ft_printf("%s %*d %-*s  %-*s", mylist->perm, big_hard,
		mylist->hardlinks, big_pw, mylist->pwname, big_gr,
		mylist->grname);
		if (mylist->minor || mylist->major)
			ft_printf(" %*lld, %*d", big_size_maj, mylist->major, big_size, mylist->minor);
		else if (have_maj_min)
		{
			ft_printf(" %*s", big_size_maj, "i ");
			ft_printf(" %*lld", big_size, mylist->size);
		}
		else
			ft_printf(" %*lld", big_size, mylist->size);
		ft_printf(" %s", ft_strsub(mylist->date_string, 4, 3));
		ft_printf(" %s", ft_strsub(mylist->date_string, 8, 2));
		if (actualtime - mylist->date < 15778800)
			ft_printf(" %s ", ft_strsub(mylist->date_string, 11, 5));
		else
			ft_printf("  %s ", ft_strsub(mylist->date_string, 20, 4));
		if (mylist->have_symlink != NULL)
			ft_printf("%s -> %s\n", mylist->file_name, mylist->have_symlink);
		else
			print_filename_color(mylist);
		mylist = mylist->next;
	}
}

void		fill_perm(t_list_ls *tmp, struct stat *fs)
{
	if (S_ISDIR(fs->st_mode))
	{
		tmp->perm[0] = 'd';
		tmp->is_dir = 1;
	}
	else if (S_ISREG(fs->st_mode))
		tmp->perm[0] = '-';
	else if (S_ISLNK(fs->st_mode))
		tmp->perm[0] = 'l';
	else if (S_ISCHR(fs->st_mode))
		tmp->perm[0] = 'c';
	else if (S_ISSOCK(fs->st_mode))
		tmp->perm[0] = 's';
	else if (S_ISFIFO(fs->st_mode))
		tmp->perm[0] = 'p';
	else if (S_ISDIR(fs->st_mode))
		tmp->perm[0] = 'd';
	else if (S_ISBLK(fs->st_mode))
		tmp->perm[0] = 'b';
	else
		tmp->perm[0] = '-';
}
