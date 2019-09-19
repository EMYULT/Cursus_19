/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:12:37 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/19 13:12:38 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	fill_perm_right(t_list_ls *tmp, struct stat *fs)
{
	tmp->perm[1] = ((fs->st_mode & S_IRUSR) ? 'r' : '-');
	tmp->perm[2] = ((fs->st_mode & S_IWUSR) ? 'w' : '-');
	if (fs->st_mode & S_IXUSR)
	{
		tmp->perm[3] = 'x';
		if (tmp->is_dir != 1)
			tmp->is_dir = 666;
	}
	else
		tmp->perm[3] = '-';
	tmp->perm[4] = ((fs->st_mode & S_IRGRP) ? 'r' : '-');
	tmp->perm[5] = ((fs->st_mode & S_IWGRP) ? 'w' : '-');
	tmp->perm[6] = ((fs->st_mode & S_IXGRP) ? 'x' : '-');
	tmp->perm[7] = ((fs->st_mode & S_IROTH) ? 'r' : '-');
	tmp->perm[8] = ((fs->st_mode & S_IWOTH) ? 'w' : '-');
	tmp->perm[9] = ((fs->st_mode & S_IXOTH) ? 'x' : '-');
}

void	fill_acl(t_list_ls *tmp, struct stat *fs, char *tmp2)
{
	acl_t		tmpacl;

	tmpacl = NULL;
	if (S_ISUID & fs->st_mode)
		tmp->perm[3] = (tmp->perm[3] == '-') ? 'S' : 's';
	if (S_ISGID & fs->st_mode)
		tmp->perm[6] = (tmp->perm[6] == '-') ? 'S' : 's';
	if (S_ISVTX & fs->st_mode)
		tmp->perm[9] = (tmp->perm[9] == '-') ? 'T' : 't';
	if (listxattr(tmp2, NULL, 0, XATTR_NOFOLLOW) > 0)
		tmp->perm[10] = '@';
	else if ((tmpacl = acl_get_link_np(tmp2, ACL_TYPE_EXTENDED)))
	{
		acl_free((void *)tmpacl);
		tmp->perm[10] = '+';
	}
	else
		tmp->perm[10] = ' ';
	tmp->perm[11] = '\0';
}
