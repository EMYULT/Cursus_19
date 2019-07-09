/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:19:50 by tjuzen            #+#    #+#             */
/*   Updated: 2019/07/06 11:19:51 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		fill_perm_right(t_list_ls *tmp, struct stat fs)
{
	tmp->perm[1] = ((fs.st_mode & S_IRUSR) ? 'r' : '-');
	tmp->perm[2] = ((fs.st_mode & S_IWUSR) ? 'w' : '-');
	if (fs.st_mode & S_IXUSR)
	{
		tmp->perm[3] = 'x';
		if (tmp->is_dir != 1)
			tmp->is_dir = 666;
	}
	else
		tmp->perm[3] = '-';
	tmp->perm[4] = ((fs.st_mode & S_IRGRP) ? 'r' : '-');
	tmp->perm[5] = ((fs.st_mode & S_IWGRP) ? 'w' : '-');
	tmp->perm[6] = ((fs.st_mode & S_IXGRP) ? 'x' : '-');
	tmp->perm[7] = ((fs.st_mode & S_IROTH) ? 'r' : '-');
	tmp->perm[8] = ((fs.st_mode & S_IWOTH) ? 'w' : '-');
	tmp->perm[9] = ((fs.st_mode & S_IXOTH) ? 'x' : '-');
}

void		fill_perm_acl(acl_t tmpacl, t_list_ls *tmp, struct stat fs, char *tmp2)
{
	if (S_ISUID & fs.st_mode)
		tmp->perm[3] = (tmp->perm[3] == '-') ? 'S' : 's';
	if (S_ISGID & fs.st_mode)
		tmp->perm[6] = (tmp->perm[6] == '-') ? 'S' : 's';
	if (S_ISVTX & fs.st_mode)
		tmp->perm[9] = (tmp->perm[9] == '-') ? 'T' : 't';
	if (listxattr(tmp2, NULL, 0, XATTR_NOFOLLOW) > 0)
		tmp->perm[10] = '@';
	else if ((tmpacl = acl_get_link_np(tmp2, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmpacl);
		tmp->perm[10] = '+';
	}
	else
		tmp->perm[10] = ' ';
	tmp->perm[11] = '\0';
}

void		fill_others(t_list_ls *tmp, struct stat fs, t_arg_ls *arg, char *tmp2)
{
	char buf[NAME_MAX + 1];

	tmp->date = fs.st_mtime;
	tmp->hardlinks = fs.st_nlink;
	tmp->size = (long long)fs.st_size;
	arg->totalsize += fs.st_blocks;
	tmp->pwname = ft_strdup(getpwuid(fs.st_uid)->pw_name);
	tmp->grname = ft_strdup(getgrgid(fs.st_gid)->gr_name);
	tmp->date_string = ft_strdup((ctime(&fs.st_mtime)));
	if (tmp->perm[0] == 'l')
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(tmp2, buf, NAME_MAX);
		tmp->have_symlink = ft_strdup(buf);
	}
	else
		tmp->have_symlink = NULL;
	if (!tmp->date_string || !tmp->grname || !tmp->pwname)
		return ;
	// Attention ce check est surement mauvais ..
}

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
