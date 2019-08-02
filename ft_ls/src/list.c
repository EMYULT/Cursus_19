/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:19:50 by tjuzen            #+#    #+#             */
/*   Updated: 2019/07/31 11:38:37 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*add_link_front(t_list_ls *mylist, char *str, t_arg_ls *arg)
{
	t_list_ls	*tmp;
	acl_t		tmpacl;
	struct stat	fs;
	char		*tmp2;

	tmpacl = NULL;
	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		tmp2 = ft_strjoin(arg->path, tmp->file_name);
		if (lstat(tmp2, &fs) < 0 || !tmp2)
			return (NULL);
		fill_perm(tmp, fs);
		fill_perm_right(tmp, fs);
		fill_perm_acl(tmpacl, tmp, fs, tmp2);
		fill_others(tmp, fs, arg, tmp2);
		tmp->next = mylist;
	}
	else
		return (NULL);
	return (tmp);
}
