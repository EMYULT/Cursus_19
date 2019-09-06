/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:19:50 by tjuzen            #+#    #+#             */
/*   Updated: 2019/09/06 11:36:15 by hde-ghel         ###   ########.fr       */
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
	if (!(tmp = ft_memalloc(sizeof(t_list_ls))))
		return (NULL);
	tmp->file_name = str;
	tmp2 = ft_strjoin(arg->path, tmp->file_name);
	if (lstat(tmp2, &fs) < 0 || !tmp2)
	{
		ft_strdel(&tmp2);
		tmp2 = ft_strdup(tmp->file_name);
		if (lstat(tmp2, &fs) < 0 || !tmp2)
			return (NULL);
	}
	fill_perm(tmp, &fs);
	fill_perm_right(tmp, &fs);
	fill_perm_acl(tmpacl, tmp, &fs, tmp2);
	if (fill_others(tmp, &fs, arg, tmp2) == -1)
			return (NULL);
	ft_strdel(&tmp2);
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

void		permission_denied(char *path, t_arg_ls *arg, int check_last_arg)
{
	int		i;

	if (arg->flag_mutiple_folders == 1 && arg->is_in_recu != 1)
		ft_printf("%s:\n", path);
	i = ft_strlen(path);
	ft_putstr_fd("ls: ", 2);
	if (path[i -1] == '/')
		i = i - 2;
	while (i > 0 && path[i - 1] != '/')
		i--;
	while (path[i] != '\0' && path[i] != '/')
		ft_putchar_fd(path[i++], 2);
	ft_putchar_fd(':', 2);
	ft_putstr_fd(" Permission denied\n", 2);
	if (arg->flag_mutiple_folders == 1 && check_last_arg == 0)
		ft_putstr("\n");
}

t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist, t_arg_ls *arg)
{
	char	*tmp;

	if (!(d = opendir(arg->path)))
	{
		permission_denied(arg->path, arg, 1);
		return (NULL);
	}
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] != '.' || (arg->is_a == 1 && dir->d_name[0] == '.'))
		{
			if (!(tmp = ft_strdup(dir->d_name)))
			{
				closedir(d);
				return (NULL);
			}
			mylist = add_link_front(mylist, tmp, arg);
		}
	}
	closedir(d);
	return (mylist);
}
