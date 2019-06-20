/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-ghel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:50:58 by hde-ghel          #+#    #+#             */
/*   Updated: 2019/06/13 17:14:27 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

t_list_ls	*lst_swap(t_list_ls *p1, t_list_ls *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

void print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
		return;
	while(mylist != NULL)
	{
		if (mylist->is_dir == 1)
			ft_printf(CYAN"%s\n"DEFAULT_COLOR, mylist->file_name);
		else if (mylist->is_dir == 666)
			ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
		else
			ft_printf(DEFAULT_COLOR"%s\n"DEFAULT_COLOR, mylist->file_name);
		mylist = mylist->next;
	}
}

int		length_int_easy(int x)
{
    if (x >= 1000000000)
		return 10;
    if (x >= 100000000)
		return 9;
    if (x >= 10000000)
		return 8;
    if (x >= 1000000)
		return 7;
    if (x >= 100000)
		return 6;
    if (x >= 10000)
		return 5;
    if (x >= 1000)
		return 4;
    if (x >= 100)
		return 3;
    if (x >= 10)
		return 2;
    return 1;
}

void print_full_list(t_list_ls *mylist)
{
	int 		big_hard = 0;
	int 		big_pw = 0;
	int 		big_gr = 0;
	int 		big_size = 0;
	t_list_ls	*tmp = mylist;

	if (mylist == NULL)
		return;
	while (tmp != NULL)
	{
		if (length_int_easy(tmp->hardlinks) > big_hard)
			big_hard = length_int_easy(tmp->hardlinks);
		if ((int)ft_strlen(tmp->pwname) > big_pw)
			big_pw = (int)ft_strlen(tmp->pwname);
		if ((int)ft_strlen(tmp->grname) > big_gr)
			big_gr = (int)ft_strlen(tmp->grname);
		if (length_int_easy(tmp->size) > big_size)
			big_size = length_int_easy(tmp->size);
		tmp = tmp->next;
	}
	while(mylist != NULL)
	{
		ft_printf("%s  %*d %-*s  %-*s  %*lld", mylist->perm, big_hard, mylist->hardlinks, big_pw, mylist->pwname, big_gr, mylist->grname, big_size, mylist->size);
		ft_printf(" %s", ft_strsub(mylist->date_string, 4, 3));
		ft_printf(" %s", ft_strsub(mylist->date_string, 8, 2));
		ft_printf(" %s ", ft_strsub(mylist->date_string, 11, 5));
		if (mylist->is_dir == 1)
			ft_printf(CYAN"%s\n"DEFAULT_COLOR, mylist->file_name);
		else if (mylist->is_dir == 666)
			ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
		else
			ft_printf(DEFAULT_COLOR"%s\n"DEFAULT_COLOR, mylist->file_name);
		mylist = mylist->next;
	}
}

t_list_ls *reverse_list(t_list_ls *mylist)
{
	t_list_ls *prev;
	t_list_ls *current;
	t_list_ls *next;

	prev = NULL;
	next = NULL;
	current = mylist;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	mylist = prev;
	return (mylist);
}

t_list_ls *add_link_front(t_list_ls *mylist, char *str, b_arg *arg)
{
	t_list_ls	*tmp;
	struct stat	fs;
	char		*tmp2;
	struct passwd *pwd;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		tmp2= ft_strjoin(arg->path, tmp->file_name);
		if (lstat(tmp2, &fs) < 0)
		{
			ft_printf("error file doesn not exit recursive ");
			return(NULL);
		}
		pwd = getpwuid(fs.st_uid);
		tmp->date = fs.st_mtime;
		if (S_ISDIR(fs.st_mode))
		{
			tmp->perm[0] = 'd';
			tmp->is_dir = 1;
		}
		else
			tmp->perm[0] = '-';
		tmp->perm[1] = ((fs.st_mode & S_IRUSR) ? 'r' : '-');
		tmp->perm[2] = ((fs.st_mode & S_IWUSR) ? 'w' : '-');
		if (fs.st_mode & S_IXUSR && tmp->is_dir != 1)
		{
			tmp->perm[3] = 'x';
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
		tmp->perm[10] = '\0';
		tmp->hardlinks = fs.st_nlink;
		tmp->size = (long long)fs.st_size;
		tmp->pwname = pwd->pw_name;
		tmp->grname = (getgrgid(pwd->pw_gid)->gr_name);
		tmp->date_string = ft_strdup((ctime(&fs.st_mtime)));
		tmp->next = mylist;
	}
	else
		return (NULL);
	return (tmp);
}

t_list_ls	*sort_ascii(t_list_ls *mylist)
{
	if (!mylist)
		return (NULL);
	if (mylist->next && ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
		mylist = lst_swap(mylist, mylist->next);
	mylist->next = sort_ascii(mylist->next);
	if (mylist->next && ft_strcmp(mylist->file_name, mylist->next->file_name) > 0)
	{
		mylist = lst_swap(mylist, mylist->next);
		mylist->next = sort_ascii(mylist->next);
	}
	return (mylist);
}

t_list_ls	*sort_time(t_list_ls *mylist)
{
	if (!mylist)
		return (NULL);
	if (mylist->next && (mylist->date < mylist->next->date))
		mylist = lst_swap(mylist, mylist->next);
	mylist->next = sort_time(mylist->next);
	if (mylist->next && (mylist->date < mylist->next->date))
	{
		mylist = lst_swap(mylist, mylist->next);
		mylist->next = sort_time(mylist->next);
	}
	return (mylist);
}

t_list_ls *add_link_front_dir(t_list_ls *mylistdir, char *str)
{
	t_list_ls		*tmp;
	struct stat 	fs;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		if (lstat(str, &fs) < 0)
		{
			ft_printf("error file doesn not exit recursive ");
			return(NULL);
		}
		tmp->date = fs.st_mtime;
		tmp->next = mylistdir;
	}
	else
		return (NULL);
	return (tmp);
}

t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg)
{
	char *tmp;

	if (arg->is_a == 1)
	{
		if (!(d = opendir(arg->path)))
			return (NULL);
		while ((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] == '.')
			{
				if (!(tmp = strdup(dir->d_name)))
					return (NULL);
				mylist = add_link_front(mylist, tmp, arg);
			}
		}
		closedir(d);
	}
	if (!(d = opendir(arg->path)))
		return (NULL);
	while ((dir = readdir(d)) != NULL)
	{
		if (dir->d_name[0] != '.')
		{
			if (!(tmp = strdup(dir->d_name)))
				return (NULL);
			mylist = add_link_front(mylist, tmp, arg);
		}
	}
	closedir(d);
	return (mylist);
}
