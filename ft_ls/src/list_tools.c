/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:17:00 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/19 13:17:01 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		free_list_dir(t_list_ls *list, int r)
{
	t_list_ls	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (r);
}

int		free_list_file(t_list_ls *list, int r)
{
	t_list_ls	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->file_name_path != NULL)
			ft_strdel(&list->file_name_path);
		if (list->pwname != NULL)
			ft_strdel(&list->pwname);
		if (list->grname != NULL)
			ft_strdel(&list->grname);
		if (list->date_month != NULL)
			ft_strdel(&list->date_month);
		if (list->date_day != NULL)
			ft_strdel(&list->date_day);
		if (list->date_hour_year != NULL)
			ft_strdel(&list->date_hour_year);
		if (list->have_symlink != NULL)
			ft_strdel(&list->have_symlink);
		free(list);
		list = tmp;
	}
	return (r);
}

int		free_list(t_list_ls *list, int r)
{
	t_list_ls	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->file_name != NULL)
			ft_strdel(&list->file_name);
		if (list->file_name_path != NULL)
			ft_strdel(&list->file_name_path);
		if (list->pwname != NULL)
			ft_strdel(&list->pwname);
		if (list->grname != NULL)
			ft_strdel(&list->grname);
		if (list->date_month != NULL)
			ft_strdel(&list->date_month);
		if (list->date_day != NULL)
			ft_strdel(&list->date_day);
		if (list->date_hour_year != NULL)
			ft_strdel(&list->date_hour_year);
		if (list->have_symlink != NULL)
			ft_strdel(&list->have_symlink);
		free(list);
		list = tmp;
	}
	return (r);
}
