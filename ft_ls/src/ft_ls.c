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
	arg->path = ".";
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
	return (i == j) ? (1) : (check_path(str, arg));
}

int		check_path(char *str, b_arg *arg)
{
	DIR *d;
	int i;
	int j;

	j = 0;
	i = 0;
	d = opendir(str);
	if (d == NULL)
		return (-1);
	while (str[i])
		i++;
	if (str[i - 1] != '/')
	{
		if (!(arg->path = (char *)malloc(sizeof(char) * i + 2)))
			return (-1);
		while(j < i)
		{
			arg->path[j] = str[j];
			j++;
		}
		arg->path[j] = '/';
		arg->path[j + 1] = '\0';
	}
	else
		arg->path = str;
	closedir(d);
	return (1);
}

// Fonction qui applique les bons params

void	handle_arg(b_arg *arg, t_list_ls *mylist)
{

	DIR				*d;
	struct dirent	*dir;

	mylist = params(dir, d, mylist, arg);
	if (arg->is_r == 1)
		mylist = reverse_list(mylist);
	if (arg->is_l != 1)
		print_list(mylist);
}

// Cree une structure, initialise, check si args valide puis les gere

int		main(int argc, char **argv)
{
	b_arg		arg[1];
	int 		i;
	t_list_ls	*mylist;

	i = 0;
	mylist = NULL;
	initialize_arg(arg);
	while (++i < argc)
		if (check_arg(argv[i], arg, 0, 0) == -1)
		{
			ft_printf("Erreur dans les arguments");
			return (1);
		}
	handle_arg(arg, mylist);
	return (-1);
}
