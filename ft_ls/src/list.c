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

void		print_list(t_list_ls *mylist)
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

int			length_int_easy(int x)
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

void		print_full_list(t_list_ls *mylist, b_arg *arg, int flag)
{
	int 		big_hard = 0;
	int 		big_pw = 0;
	int 		big_gr = 0;
	int 		big_size = 0;
	t_list_ls	*tmp = mylist;
	time_t		actualtime;

	actualtime = time(0);
	if (mylist == NULL)
		return;
	if (flag == 0)
	{
		ft_printf("total %lld\n", arg->totalsize);
		arg->totalsize = 0;
	}
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
	  ft_printf("%s %*d %-*s  %-*s  %*lld", mylist->perm, big_hard,
	  mylist->hardlinks, big_pw, mylist->pwname, big_gr,
	  mylist->grname, big_size, mylist->size);
		ft_printf(" %s", ft_strsub(mylist->date_string, 4, 3));
		ft_printf(" %s", ft_strsub(mylist->date_string, 8, 2));
		if (actualtime - mylist->date < 15778800)
			ft_printf(" %s ", ft_strsub(mylist->date_string, 11, 5));
		else
			ft_printf("  %s ", ft_strsub(mylist->date_string, 20, 4));
		if (mylist->is_dir == 1)
			ft_printf(CYAN"%s\n"DEFAULT_COLOR, mylist->file_name);
		else if (mylist->is_dir == 666)
			ft_printf(RED"%s\n"DEFAULT_COLOR, mylist->file_name);
		else
			ft_printf(DEFAULT_COLOR"%s\n"DEFAULT_COLOR, mylist->file_name);
		mylist = mylist->next;
	}
}

t_list_ls	*reverse_list(t_list_ls *mylist)
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

void		fill_perm(t_list_ls *tmp, struct stat fs)
{
	if (S_ISDIR(fs.st_mode))
	{
		tmp->perm[0] = 'd';
		tmp->is_dir = 1;
	}
	else if (S_ISREG(fs.st_mode))
		tmp->perm[0] = '-';
	else if (S_ISLNK(fs.st_mode))
		tmp->perm[0] = 'l';
	else if (S_ISCHR(fs.st_mode))
		tmp->perm[0] = 'c';
	else if (S_ISSOCK(fs.st_mode))
		tmp->perm[0] = 's';
	else if (S_ISFIFO(fs.st_mode))
		tmp->perm[0] = 'p';
	else if (S_ISDIR(fs.st_mode))
		tmp->perm[0] = 'd';
	else if (S_ISBLK(fs.st_mode))
		tmp->perm[0] = 'b';
	else
		tmp->perm[0] = '-';
}

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

void		fill_others(t_list_ls *tmp, struct stat fs, b_arg *arg)
{
	struct passwd *pwd;

	pwd = getpwuid(fs.st_uid);
	tmp->date = fs.st_mtime;
	tmp->hardlinks = fs.st_nlink;
	tmp->size = (long long)fs.st_size;
	arg->totalsize += fs.st_blocks;
	if (pwd == NULL)
	{
		tmp->pwname = ft_strdup("test");
		tmp->grname = ft_strdup("test");
		tmp->date_string = ft_strdup((ctime(&fs.st_mtime)));
		return ;
	}
	tmp->pwname = ft_strdup(pwd->pw_name);
	tmp->grname = ft_strdup((getgrgid(pwd->pw_gid)->gr_name));
	tmp->date_string = ft_strdup((ctime(&fs.st_mtime)));
}

t_list_ls	*add_link_front(t_list_ls *mylist, char *str, b_arg *arg)
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
		if (lstat(tmp2, &fs) < 0)
			return (NULL);
		fill_perm(tmp, fs);
		fill_perm_right(tmp, fs);
		fill_perm_acl(tmpacl, tmp, fs, tmp2);
		fill_others(tmp, fs, arg);
		tmp->next = mylist;
	}
	else
		return (NULL);
	return (tmp);
}
