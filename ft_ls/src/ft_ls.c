/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/02/15 12:02:02 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// Fonction qui initialise chaque arg de ma struct

void	initialize_arg(b_arg *arg)
{
	arg->is_l = 0;
	arg->is_R = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->with_arg = 0;
}

// Fonction qui parcour argv[1] et qui check les args

int	check_arg(char *str, b_arg *arg, int i, int j)
{
	while (str[j])
		j++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return (str[i + 1]) ? (-1) : (1);
		arg->with_arg = 1;
		while (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' ||
		str[i] == 'r' || str[i] == 't')
		{
			if (str[i] == 'l')
				arg->is_l = 1;
			if (str[i] == 'R')
				arg->is_R = 1;
			if (str[i] == 'a')
				arg->is_a = 1;
			if (str[i] == 'r')
				arg->is_r = 1;
			if (str[i] == 't')
				arg->is_t = 1;
			i++;
		}
	}
	return (i != j) ? (-1) : (1);
}

// Fonction qui en fonction des args envoyés appelle la fnct adequate

void	handle_arg(b_arg *arg)
{
	t_list_ls			*mylist;
	DIR						*d;
	struct dirent	*dir;
	struct stat 	fs;

	mylist = NULL;
	if (arg->with_arg == 0)
		no_param(dir, d, mylist);
	else if (arg->is_a == 1)
	{
		if (arg->is_l == 1)
			param_l(dir, d, fs, mylist);
		if (arg->is_R == 1)
			param_R(dir, d, fs, mylist);
		if (arg->is_r == 1)
			param_r(dir, d, fs, mylist);
		if (arg->is_t == 1)
			param_t(dir, d, fs, mylist);
	}
	else
	{
		if (arg->is_l == 1)
			param_l(dir, d, fs, mylist);
		if (arg->is_R == 1)
			param_R(dir, d, fs, mylist);
		if (arg->is_r == 1)
			param_r(dir, d, fs, mylist);
		if (arg->is_t == 1)
			param_t(dir, d, fs, mylist);
	}
}

// Creer structure, initialiser, si 2 arg-> je check, sinon handle

int		main(int argc, char **argv)
{
	b_arg	arg[1];
	int i;

	i = 0;
	initialize_arg(arg);
	while (++i < argc)
		if (check_arg(argv[i], arg, 0, 0) == -1)
		{
			ft_printf("Erreur dans les arguments");
			return (1);
		}
	handle_arg(arg);
	return (-1);
}
