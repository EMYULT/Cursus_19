/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:04 by tjuzen            #+#    #+#             */
/*   Updated: 2019/02/15 12:02:05 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/ft_printf/printf.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

/* Définition de ma structure */

typedef	struct	a_arg
{
	int		with_arg;
	int		is_l;
	int		is_R;
	int		is_a;
	int		is_r;
	int		is_t;
	char	*path;
}				b_arg;

/* Définition d'une Liste */

typedef struct s_list_ls t_list_ls;

struct s_list_ls
{
	char *file_name;
	char *file_name_path;
	t_list_ls *next;
};

/* Prototypes liste */

t_list_ls 	*reverse_list(t_list_ls *mylist);
t_list_ls	*add_link_front(t_list_ls *mylist, char *str);
void 		print_list(t_list_ls *mylist);
t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg);
t_list_ls	*sort_list(t_list_ls *mylist, b_arg *arg);

/* Prototypes infos fichiers */

void	print_permissions(char *file, struct stat fs);
void	print_hardlinks(char *file, struct stat fs);
void	print_owner(char *file, struct stat fs);
void 	print_size(char *file, struct stat fs);
void	print_date(char *file, struct stat fs);


/* Prototypes arg generaux */

void	handle_arg(b_arg *arg, t_list_ls *mylist);
int		check_path(char *str, b_arg *arg);
int		check_arg(char *str, b_arg *arg, int i, int j);

/* Prototypes arg specifiques */

void	param_l(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg);
void	param_R(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg);
void	param_a(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg);
void	param_r(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg);
void	param_t(struct dirent *dir, DIR *d, struct stat fs, t_list_ls *mylist, b_arg *arg);
t_list_ls	*params(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg);

#endif
