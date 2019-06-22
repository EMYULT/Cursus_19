/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:55:14 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/22 12:55:15 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initialize_arg(b_arg *arg)
{
	arg->is_l = 0;
	arg->is_R = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->path = "./";
	arg->totalsize = 0;
	arg->coucou = 0;
}

int		check_arg(char *str, b_arg *arg, int i, int j)
{
	while (str[j])
		j++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return (str[i + 1]) ? (-1) : (1);
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
	return (i == j) ? (1) : (-1);
}

int		check_path(char *str, b_arg *arg)
{
	DIR *d;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
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
		arg->coucou = 1;
	}
	else
		arg->path = str;
	closedir(d);
	return (1);
}
