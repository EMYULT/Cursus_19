/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:01 by tjuzen            #+#    #+#             */
/*   Updated: 2019/02/15 12:02:02 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// Fonction qui parcour argv[1] et qui check les args

void	check_arg(char *str, b_arg *arg)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
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
}

// Fonction qui affiche le nmb d'hardlinks pour chaque fichiers

void	print_hardlinks(char *file, struct stat fs)
{
	if (stat(file,&fs) < 0)
		ft_printf("error\n");
	else
		ft_printf("%4d", fs.st_nlink);
}

// Fonction qui m'affiche la taille en bytes de mon fichier

void print_size(char *file, struct stat fs)
{
	if (stat(file, &fs) == -1)
		ft_printf("error");
	else
    	ft_printf(" %6lld ", (long long) fs.st_size);
}

// Fonction qui affiche le proprietaire pour chaque fichiers

void	print_owner(char *file, struct stat fs)
{
	struct group *gr;
	struct passwd *pwd;
	uid_t uid;

	uid = 0;
	if ((gr = getgrgid(uid)) != NULL)
	    ft_printf(" %s ", gr->gr_name);
	pwd = getpwuid(uid);
	ft_printf(" %s ", pwd->pw_name);
}

// Fonction qui affiche les permissions de chaque fichiers
// Pas moi qui l'ait fait !!!

void	print_permissions(char *file, struct stat fs)
{
	if (stat(file,&fs) < 0)
	{
		ft_printf("Erreur frero\n");
		return ;
	}
	ft_printf((S_ISDIR(fs.st_mode)) ? "d" : "-");
	ft_printf((fs.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fs.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fs.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fs.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fs.st_mode & S_IXOTH) ? "x " : "- ");
}

// Fonction qui m'affiche le mois, jour et heure de la derniere modif du fichiers

void	print_date(char *file, struct stat fs)
{
	struct stat date;
	struct tm *p;
	if (stat(file, &date) < 0)
		ft_printf("error");
	else
	{
		p = gmtime(&(date.st_mtime));
		ft_printf(" %d ", p->tm_year);
	 	ft_printf(" %d ", p->tm_mon);
	  	ft_printf(" %d ", p->tm_mday);
	  	ft_printf(" %d ", p->tm_hour);
	  	ft_printf(" %d ", p->tm_min);
	}

}

// Fonction qui en fonction des args envoyés appelle la fnct adequate

void	handle_arg(b_arg *arg)
{
	List mylist = new_list();
	DIR				*d;
	struct dirent	*dir;
	struct stat 	fs;

	if (arg->with_arg == 0)
		no_param(dir, d, mylist);
	else if (arg->is_l == 1)
		param_l(dir, d, fs, mylist);
	else if (arg->is_R == 1)
		param_R(dir, d, fs, mylist);
	else if (arg->is_a == 1)
		param_a(dir, d, fs, mylist);
	else if (arg->is_r == 1)
		param_r(dir, d, fs, mylist);
	else if (arg->is_t == 1)
		param_t(dir, d, fs, mylist);
}

// Fonction qui initialise chaque arg de ma struct

void	initialize_arg(b_arg *arg)
{
	arg->is_l = 0;
	arg->is_R = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->with_arg = 0;
}

// Creer structure, initialiser, si 2 arg-> je check, sinon handle

int		main(int argc, char **argv)
{
	b_arg	*arg;

	initialize_arg(arg);
	if (argc == 2)
		check_arg(argv[1], arg);
	handle_arg(arg);
	return (0);
}
