
#include "../includes/ft_ls.h"

void print_list(t_list_ls *mylist)
{
	if (mylist == NULL)
	{
		ft_printf("Rien a afficher, la Liste est vide.\n");
		return;
	}
	while(mylist != NULL)
	{
		ft_printf("%s\n", mylist->file_name);
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
			next  = current->next;
			current->next = prev;
			prev = current;
			current = next;
	}
	mylist = prev;
	return (mylist);
}

t_list_ls *add_link_front(t_list_ls *mylist, char *str)
{
	t_list_ls *tmp;

	tmp = malloc(sizeof(t_list_ls));
	if (tmp)
	{
		tmp->file_name = str;
		tmp->next = mylist;
	}
	return (tmp);
}

t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] >= 65 && dir->d_name[0] <= 90)
			mylist = add_link_front(mylist, dir->d_name);
	closedir(d);
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.' && (dir->d_name[0] < 65 || dir->d_name[0] > 90))
			mylist = add_link_front(mylist, dir->d_name);
	closedir(d);
	return (mylist);
}

t_list_ls	*push_list_hidden(struct dirent *dir, DIR *d, t_list_ls *mylist)
{
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] == '.')
			mylist = add_link_front(mylist, dir->d_name);
	closedir(d);
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] >= 65 && dir->d_name[0] <= 90)
			mylist = add_link_front(mylist, dir->d_name);
	closedir(d);
	d = opendir(".");
	while ((dir = readdir(d)) != NULL)
		if (dir->d_name[0] != '.' && (dir->d_name[0] < 65 || dir->d_name[0] > 90))
			mylist = add_link_front(mylist, dir->d_name);
	closedir(d);
	return (mylist);
}
