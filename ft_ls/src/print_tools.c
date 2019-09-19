/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:15:27 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/19 13:15:28 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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
