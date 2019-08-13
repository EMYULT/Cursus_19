/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:36:01 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/08/12 17:10:12 by hde-ghel         ###   ########.fr       */
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

char		*fill_group(struct stat fs)
{
	struct group *g;
	char	*pwname;

	g = getgrgid(fs.st_gid);
	if (g && g->gr_name)
	{
		pwname = ft_strdup(g->gr_name);
		return (pwname);
	}
	else
		return (ft_itoa(fs.st_gid));
}

char		*fill_pwname(struct stat fs)
{
	struct  passwd	*p;
	char			*pw_name_tmp;


	p = getpwuid(fs.st_uid);
	if (p && p->pw_name)
	{
		pw_name_tmp = ft_strdup(p->pw_name);
		return (pw_name_tmp);
	}
	else
		return (ft_itoa(fs.st_uid));
}

int		fill_others(t_list_ls *tmp, struct stat fs, t_arg_ls *arg, char *tmp2)
{
	char buf[NAME_MAX + 1];

	tmp->date = fs.st_mtime;
	tmp->hardlinks = fs.st_nlink;
	tmp->size = (long long)fs.st_size;
	arg->totalsize += fs.st_blocks;
	//protection ! (print malloc error)
	if (!(tmp->grname = fill_group(fs)))
		return(-1);
	if (!(tmp->pwname = fill_pwname(fs)))
		return (-1);
	tmp->date_string = ft_strdup((ctime(&fs.st_mtime)));
	if (tmp->perm[0] == 'l')
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(tmp2, buf, NAME_MAX);
		tmp->have_symlink = ft_strdup(buf);
	}
	else
		tmp->have_symlink = NULL;
	return (0);
}
