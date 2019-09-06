/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:51:47 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/06 11:36:12 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_filename_color(t_list_ls *mylist)
{
	/*
	if (mylist->is_dir == 1)
		ft_printf(CYAN"%s\n"DEFAULT_COLOR, mylist->file_name);
	else if (mylist->is_dir == 666)
		ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
	else
	*/
		ft_printf("%s\n", mylist->file_name);
		//ft_printf(DEFAULT_COLOR"%s\n"DEFAULT_COLOR, mylist->file_name);
}

void	print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
		return ;
	while (mylist != NULL)
	{
		print_filename_color(mylist);
		mylist = mylist->next;
	}
}

int		length_int_easy(int x)
{
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}

void	get_big(t_arg_lsbig *arg2, t_list_ls *mylist)
{
	t_list_ls *tmp;

	tmp = mylist;
	while (tmp != NULL)
	{
		if (length_int_easy(tmp->hardlinks) > arg2->big_hard)
			arg2->big_hard = length_int_easy(tmp->hardlinks);
		if ((int)ft_strlen(tmp->pwname) > arg2->big_pw)
			arg2->big_pw = (int)ft_strlen(tmp->pwname);
		if ((int)ft_strlen(tmp->grname) > arg2->big_gr)
			arg2->big_gr = (int)ft_strlen(tmp->grname);
		if (tmp->perm[0] == 'c' || tmp->perm[0] == 'b')
		{
			arg2->have_maj_min = 1;
			if (length_int_easy(tmp->major) > arg2->big_size_maj)
				arg2->big_size_maj = length_int_easy(tmp->major);
			if (length_int_easy(tmp->minor) > arg2->big_size)
				arg2->big_size = length_int_easy(tmp->minor);
		}
		else if (length_int_easy(tmp->size) > arg2->big_size)
			arg2->big_size = length_int_easy(tmp->size);
		tmp = tmp->next;
	}
}

void	print_all(t_arg_lsbig *arg2, t_list_ls *mylist)
{
	while (mylist != NULL)
	{
		ft_printf("%s %*d %-*s  %-*s", mylist->perm, arg2->big_hard,
		mylist->hardlinks, arg2->big_pw, mylist->pwname, arg2->big_gr,
		mylist->grname);
		if (mylist->perm[0] == 'c' || mylist->perm[0] == 'b')
			ft_printf(" %*lld, %*d", arg2->big_size_maj + 2,
			mylist->major, arg2->big_size, mylist->minor);
		else if (arg2->have_maj_min)
		{
			ft_printf(" %*s", arg2->big_size_maj + 3, " ");
			ft_printf(" %*lld", arg2->big_size, mylist->size);
		}
		else
			ft_printf(" %*lld", arg2->big_size + 1, mylist->size);
		ft_printf(" %s", mylist->date_month);
		ft_printf(" %s", mylist->date_day);
		ft_printf(" %s ", mylist->date_hour_year);
		if (mylist->have_symlink != NULL)
			ft_printf("%s -> %s\n", mylist->file_name, mylist->have_symlink);
		else
			print_filename_color(mylist);
		mylist = mylist->next;
	}
}

void	print_full_list(t_list_ls *mylist, t_arg_ls *arg, int flag)
{
	t_arg_lsbig arg2;

	init_arg_2(&arg2);
	if (mylist == NULL)
		return ;
	if (flag == 0)
	{
		ft_printf("total %lld\n", arg->totalsize);
		arg->totalsize = 0;
	}
	get_big(&arg2, mylist);
	print_all(&arg2, mylist);
}

void	fill_perm(t_list_ls *tmp, struct stat *fs)
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
