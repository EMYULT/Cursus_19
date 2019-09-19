/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:36:01 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/18 14:08:51 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*fill_group(struct stat *fs, t_arg_ls *arg)
{
	struct group	*g;
	char			*pwname;

	g = getgrgid(fs->st_gid);
	if (g && g->gr_name && arg->is_n == 0)
	{
		if (!(pwname = ft_strdup(g->gr_name)))
			return (NULL);
		return (pwname);
	}
	else
		return (ft_itoa(fs->st_gid));
}

char	*fill_pwname(struct stat *fs, t_arg_ls *arg)
{
	struct passwd	*p;
	char			*pw_name_tmp;

	p = getpwuid(fs->st_uid);
	if (p && p->pw_name && arg->is_n == 0)
	{
		if (!(pw_name_tmp = ft_strdup(p->pw_name)))
			return (NULL);
		return (pw_name_tmp);
	}
	else
		return (ft_itoa(fs->st_uid));
}

int		fill_date(struct stat *fs, t_list_ls *tmp)
{
	char		*tmp_date;
	int			age;

	tmp->date = fs->st_mtime;
	age = time(0) - fs->st_mtime;
	tmp_date = ctime(&fs->st_mtime);
	tmp->date_month = ft_strsub(tmp_date, 4, 3);
	tmp->date_day = ft_strsub(tmp_date, 8, 2);
	if (age > 15724800 || age < 0)
		tmp->date_hour_year = ft_strsub(tmp_date, 19, 5);
	else
		tmp->date_hour_year = ft_strsub(tmp_date, 11, 5);
	if (!tmp->date_month || !tmp->date_day || !tmp->date_hour_year)
		return (-1);
	return (0);
}

void	fill_major_minor(t_list_ls *tmp, struct stat *fs)
{
	if (tmp->perm[0] == 'c' || tmp->perm[0] == 'b')
	{
		tmp->major = major(fs->st_rdev);
		tmp->minor = minor(fs->st_rdev);
	}
	else
		tmp->size = (long long)fs->st_size;
}

int		fill_others(t_list_ls *tmp, struct stat *fs, t_arg_ls *arg, char *tmp2)
{
	char buf[NAME_MAX + 1];

	tmp->hardlinks = fs->st_nlink;
	fill_major_minor(tmp, fs);
	arg->totalsize += fs->st_blocks;
	if (!(tmp->grname = fill_group(fs, arg)))
		return (-1);
	if (!(tmp->pwname = fill_pwname(fs, arg)))
		return (-1);
	if (fill_date(fs, tmp) == -1)
		return (-1);
	if (tmp->perm[0] == 'l')
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(tmp2, buf, NAME_MAX);
		if (!(tmp->have_symlink = ft_strdup(buf)))
			return (-1);
	}
	else
		tmp->have_symlink = NULL;
	return (0);
}
