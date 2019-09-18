/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:53:28 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/09/18 13:53:52 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_ls	*init_list(void)
{
	t_list_ls	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	tmp->file_name = NULL;
	tmp->file_name_path = NULL;
	tmp->have_symlink = NULL;
	tmp->no_file = NULL;
	tmp->pwname = NULL;
	tmp->grname = NULL;
	tmp->date_month = NULL;
	tmp->date_day = NULL;
	tmp->date_hour_year = NULL;
	return (tmp);
}

t_list_ls	*add_link_front(t_list_ls *mylist, char *str, t_arg_ls *arg)
{
	t_list_ls	*tmp;
	struct stat	fs;
	char		*full_path;

	if (!(tmp = init_list()))
		return (NULL);
	tmp->file_name = str;
	if (!(full_path = ft_strjoin(arg->path, tmp->file_name)))
		return (NULL);
	if (lstat(full_path, &fs) < 0 || !full_path)
	{
		ft_strdel(&full_path);
		if (!(full_path = ft_strdup(tmp->file_name)))
			return (NULL);
		if (lstat(full_path, &fs) < 0)
			return (mylist);
	}
	fill_perm(tmp, &fs);
	fill_perm_right(tmp, &fs);
	fill_acl(tmp, &fs, full_path);
	if (fill_others(tmp, &fs, arg, full_path) == -1)
		return (NULL);
	ft_strdel(&full_path);
	tmp->next = mylist;
	return (tmp);
}

t_list_ls	*add_link_front_dir(t_list_ls *mylistdir, char *str)
{
	t_list_ls		*tmp;
	struct stat		fs;

	tmp = ft_memalloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		if (lstat(str, &fs) < 0)
			return (NULL);
		tmp->date = fs.st_mtime;
		tmp->next = mylistdir;
	}
	else
		return (NULL);
	return (tmp);
}

int			permission_denied(char *path, t_arg_ls *arg, int check_last_arg)
{
	int		i;

	if (arg->flag_mutiple_folders == 1 && arg->is_in_recu != 1)
		ft_printf("%s:\n", path);
	i = ft_strlen(path);
	ft_putstr_fd("ls: ", 2);
	if (path[i - 1] == '/')
		i = i - 2;
	while (i > 0 && path[i - 1] != '/')
		i--;
	while (path[i] != '\0' && path[i] != '/')
		ft_putchar_fd(path[i++], 2);
	ft_putchar_fd(':', 2);
	ft_putstr_fd(" Permission denied\n", 2);
	if (arg->flag_mutiple_folders == 1 && check_last_arg == 0)
		ft_putstr("\n");
	return (1);
}

t_list_ls	*push(t_list_ls *mylist, t_arg_ls *arg, DIR *d, struct dirent *dir)
{
	char	*tmp;

	arg->malloc_error = 0;
	if (!(d = opendir(arg->path)) && permission_denied(arg->path, arg, 1))
		return (NULL);
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] != '.' || (arg->is_a == 1 && dir->d_name[0] == '.'))
		{
			if (!(tmp = ft_strdup(dir->d_name)))
			{
				arg->malloc_error = 1;
				closedir(d);
				return (NULL);
			}
			if (!(mylist = add_link_front(mylist, tmp, arg)))
			{
				arg->malloc_error = 1;
				closedir(d);
				return (NULL);
			}
		}
	}
	closedir(d);
	return (mylist);
}
