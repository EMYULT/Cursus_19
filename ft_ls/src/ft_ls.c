/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/10 18:43:30 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// Fonction qui initialise chaque arg de ma struct

void	initialize_arg(b_arg *arg)
{
	arg->is_l = 0;
	arg->is_R = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->with_arg = 0;
	arg->path = "./";
	arg->dir_path = NULL;
}

// Fonction qui parcour argv[1] et qui check les args

int	check_arg(char *str, b_arg *arg, int i, int j)
{
	while (str[j])
		j++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		if (str[i] == '-')
			return (str[i + 1]) ? (-1) : (1);
		arg->with_arg = 1;
		while (str[i] == 'l' || str[i] == 'R' || str[i] == 'a' ||
		str[i] == 'r' || str[i] == 't')
		{
			if (str[i] == 'l')
				arg->is_l = 1;
			if (str[i] == 'R')
				arg->is_R = 1;
			if (str[i] == 'a')
				arg->is_a = 1;
			if (str[i] == 'r')
				arg->is_r = 1;
			if (str[i] == 't')
				arg->is_t = 1;
			i++;
		}
	}
	return (i == j) ? (1) : (-1);
}

int		check_path(char *str, b_arg *arg)
{
	DIR *d;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	d = opendir(str);
	if (d == NULL)
		return (-1);
	while (str[i])
		i++;
	if (str[i - 1] != '/')
	{
		if (!(arg->path = (char *)malloc(sizeof(char) * i + 2)))
			return (-1);
		while(j < i)
		{
			arg->path[j] = str[j];
			j++;
		}
		arg->path[j] = '/';
		arg->path[j + 1] = '\0';
	}
	else
		arg->path = str;
	closedir(d);
	return (1);
}

void 	recursive_dir(b_arg *arg, t_list_ls *mylist)
{
	struct stat	fs;
	char	*tmp;

	tmp = arg->path;
	while (mylist != NULL)
	{
		// ft_printf("Mon file_name = %s\n", mylist->file_name);
		mylist->file_name_path = ft_strjoin(tmp, mylist->file_name);
		//ft_printf("Mon file_name_path = %s\n", mylist->file_name_path);
		if (lstat(mylist->file_name_path, &fs) < 0)
		{
			ft_printf("eeeerror\n");
			return ;
		}
		if (S_ISDIR(fs.st_mode))
		{
			arg->path = ft_strjoin(mylist->file_name_path, "/");
			//ft_printf("Mon arg->path = %s\n", arg->path);
			ft_printf("\n%s:\n", mylist->file_name_path);
			handle_arg(arg);
		}
		//printf("\033[0;31m" "\n%s:\n""\033[0m", mylist->file_name_path);
		mylist = mylist->next;
		
	}
}
// Fonction qui applique les bons params

void	handle_arg(b_arg *arg)
{

	DIR				*d;
	struct dirent	*dir;
	t_list_ls		*mylist;
	mylist = NULL;
	mylist = params(dir, d, mylist, arg);

	if (arg->is_r == 1)
		mylist = reverse_list(mylist);
	if (arg->is_l != 1)
		print_list(mylist);
	if (arg->is_R)
		recursive_dir(arg, mylist);
}

// Cree une structure, initialise, check si args valide puis les gere

/*
**	if (nb_path != 1) condition à revoir pour l'affichage
**  faire un sort_list_dates (comme le sort_list dans list.c) qui sort en fonction des dates
**  utiliser les fonctions de retour d'Erreur
**  regarder pq le -l est gogol
*/

int		main(int argc, char **argv)
{
	b_arg			arg[1];
	int				i;
	int				nb_path;

	i = 1;
	nb_path = 0;
	initialize_arg(arg);

	while (i < argc && argv[i][0] == '-')
	{
		if (check_arg(argv[i], arg, 0, 0) == -1)
		{
			ft_printf("Erreur dans les arguments");
			return (1);
		}
		i++;
	}
	if (argv[i])
		nb_path = argc - i;
	else
		nb_path = 1;

	int flag;
	flag = 0;
	if (argv[i] && argv[i + 1])
		flag = 1;
	// ft_printf("Mon i = %i\n", i);
	// ft_printf("Mon nb_path = %i\n", nb_path);

	while (nb_path--)
	{
		if (check_path(argv[i], arg) == -1)
		{
			ft_printf("Erreur dans les paths");
			return (1);
		}
		if (flag == 1)
			ft_printf("%s:\n", arg->path);
		handle_arg(arg);
		if (nb_path != 0)
			ft_printf("\n");
		i++;
	}
	return (-1);
}
