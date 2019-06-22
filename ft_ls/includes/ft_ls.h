/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:02:04 by tjuzen            #+#    #+#             */
/*   Updated: 2019/06/13 14:50:52 by hde-ghel         ###   ########.fr       */
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

/*
** Code couleur pour fichiers, dossiers et exec
*/

#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"
#define DEFAULT_COLOR "\033[0;m"

/*
** Définition de ma structure
*/

typedef	struct	a_arg
{
	int				is_l;
	int				is_R;
	int				is_a;
	int				is_r;
	int				is_t;
	char			*path;
	int				totalsize;
	int 			coucou;
}				b_arg;

/*
** Définition d'une liste
*/

typedef struct s_list_ls t_list_ls;

struct s_list_ls
{
	char			*file_name;
	char			*file_name_path;
	time_t			date;
	int				is_dir;
	int				hardlinks;
	long long int	size;
	char			*pwname;
	char			*grname;
	char			*date_string;
	char			perm[11];
	t_list_ls		*next;
};

/*
** Prototypes listes
*/

/*
** list.c
*/

void 		print_list(t_list_ls *mylist);
int			length_int_easy(int x);
void 		print_full_list(t_list_ls *mylist, b_arg *arg, int flag);
t_list_ls	*reverse_list(t_list_ls *mylist);
t_list_ls 	*add_link_front(t_list_ls *mylist, char *str, b_arg *arg, int flag);

/*
** list_2.c
*/

t_list_ls	*sort_ascii(t_list_ls *mylist);
t_list_ls	*sort_time(t_list_ls *mylist);
t_list_ls 	*add_link_front_dir(t_list_ls *mylistdir, char *str);
t_list_ls	*push_list(struct dirent *dir, DIR *d, t_list_ls *mylist, b_arg *arg);
t_list_ls	*lst_swap(t_list_ls *p1, t_list_ls *p2);

/*
** Prototypes ft_ls
*/

/*
** tools.c
*/

int			check_path(char *str, b_arg *arg);
int			check_arg(char *str, b_arg *arg, int i, int j);
void		initialize_arg(b_arg *arg);
t_list_ls	*check_sort(t_list_ls *mylist, b_arg *arg);
void 		display_my_files(t_list_ls *mylist, b_arg *arg);
void 		display_my_dir(t_list_ls *mylist, b_arg *arg);
int 		check_my_options(int i, int argc, char **argv, b_arg *arg);
t_list_ls	 *fill_dir(int i, int argc, char **argv);
t_list_ls 	*fill_file(int i, int argc, char **argv, b_arg *arg);

/*
** ft_ls.c
*/

int			main(int argc, char **argv);
void		handle_arg(b_arg *arg);
void		recursive_dir(b_arg *arg, t_list_ls *mylist);
t_list_ls	*params(t_list_ls *mylist, b_arg *arg);


#endif
