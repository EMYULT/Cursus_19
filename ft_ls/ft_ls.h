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

#include "libft/ft_printf/printf.h"
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
	int with_arg;
	int is_l;
	int is_R;
	int is_a;
	int is_r;
	int is_t;
}				b_arg;

/* Définition d'un Booléen */

typedef enum
{
	false,
	true
}Bool;

/* Définition d'une Liste */

typedef struct ListElement
{
	char *value;
	struct ListElement *next;
}ListElement, *List;

/* Prototypes liste */

List	new_list(void);
Bool	is_empty_list(List li);
void	print_list(List li);
int		list_length(List li);
List	push_back_list(List li, char *str);
List	push_front_list(List li, char *str);
List	pop_back_list(List li);
List	pop_front_list(List li);
List	clear_list(List li);
void	print_list_infos(struct dirent *dir, DIR *d, struct stat fs, List li);

/* Prototypes ft_ls */

void	print_permissions(char *file, struct stat fs);
void	print_hardlinks(char *file, struct stat fs);
void	print_owner(char *file, struct stat fs);
void 	print_size(char *file, struct stat fs);
void	print_date(char *file, struct stat fs);

/* Prototypes arg */

void	param_l(struct dirent *dir, DIR *d, struct stat fs, List mylist);
void	param_R(struct dirent *dir, DIR *d, struct stat fs, List mylist);
void	param_a(struct dirent *dir, DIR *d, struct stat fs, List mylist);
void	param_r(struct dirent *dir, DIR *d, struct stat fs, List mylist);
void	param_t(struct dirent *dir, DIR *d, struct stat fs, List mylist);
void	no_param(struct dirent *dir, DIR *d, List mylist);

#endif
