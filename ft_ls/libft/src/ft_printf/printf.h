/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:47:21 by tjuzen            #+#    #+#             */
/*   Updated: 2018/12/13 16:10:06 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../../includes/libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct	s_arg
{
	int		is_minus;
	int		is_plus;
	int		is_space;
	int		is_hashtag;
	int		is_zero;
	int		with_arg;
	char	*args;
	char	specifier;
	int		width;
	int		precision;
	int		length;
	int		ret;
	int		no_precision;
	int		flag1;
	int		flag2;
	int		count;
	int		flag666;
}				t_arg;

/*
**PRINTF.C
*/

int				print_to_percent(char *str, int start, t_arg *arg);
int				print_input(char *input, va_list v_arg, t_arg *arg, int i);
int				ft_printf(const char *format, ...);

/*
**CHECK.C
*/

int				ft_check_arg(t_arg *arg, va_list v_arg);
int				check_length(t_arg *arg, int *i);
int				check_precision(t_arg *arg, int *i, va_list v_arg);
int				check_width(t_arg *arg, int *i, va_list v_arg);
int				check_flags(t_arg *arg, int *i);

/*
** HANDLE_SPEC.C
*/

void			handle_point(va_list v_arg, t_arg *arg);
void			handle_hex(va_list v_arg, t_arg *arg);
void			handle_float(va_list v_arg, t_arg *arg);
void			handle_hexx(va_list v_arg, t_arg *arg);
void			handle_char(va_list v_arg, t_arg *arg);
void			handle_integer(va_list v_arg, t_arg *arg);
int				int_modifier(t_arg *arg, va_list v_arg);
void			handle_unsigned_long(va_list v_arg, t_arg *arg);
void			handle_octal(va_list v_arg, t_arg *arg);
void			octal_modifier(t_arg *arg, unsigned long long di);
void			handle_string(va_list v_arg, t_arg *arg);
void			handle_x_modifier(t_arg *arg, va_list v_arg);
void			unsigned_modifier(t_arg *arg, unsigned long long di);
int				handle_percent(t_arg *arg, int i);

/*
** TOOLS.C
*/

void			initialize(t_arg *arg);
int				ft_atoi_sub(const char *str, int start, int len);
void			ft_putnbr_no_sign(long long n, t_arg *arg);
void			ft_putchar_ret(char c, t_arg *arg);
void			ft_putstr_ret(char const *s, t_arg *arg);
int				ft_isusable(char c);
int				ft_isflag(int c);
int				check_spec(t_arg *arg, va_list v_arg);
int				get_spec(char *input, t_arg *arg, int i, va_list v_arg);
char			*ft_itoa_base_unsigned(unsigned long long n, int base);
char			*ft_itoa_unsigned(unsigned long long int n);
char			*ft_itoa_base(long long n, int base);
int				with_arg(va_list v_arg, t_arg *arg);
int				ft_atoi(const char *str);
void			ft_putchar_ret_count(char c, t_arg *arg);
void			ft_putstr_ret_count(char const *s, t_arg *arg);
void			ft_putnbr_unsigned(unsigned long long n, t_arg *arg);

/*
** DISPLAY.C
*/
void			float_round(t_arg *arg, long double i);
void			put_or_not_i(long long c, t_arg *arg, const char *str, int i);
void			put_or_not(unsigned long long c, t_arg *arg
				, const char *str, int i);
int				precision_no_m(const char *str, t_arg *arg, int i);
int				precision_m(const char *str, t_arg *arg, int i);
void			avec_minus(char *str, t_arg *arg);
void			sans_minus(char *str, t_arg *arg);
void			ft_chrmin(int c, t_arg *arg);
void			ft_chrnmin(int c, t_arg *arg);
void			print_flags(t_arg *arg, int i, const char *str);
int				int_prec_no_m(const char *str, t_arg *arg, int i, long long c);
int				int_prec_m(const char *str, t_arg *arg, int i, long long c);
void			ft_intm(const char *str, t_arg *arg, long long c);
void			ft_intnm(const char *str, t_arg *arg, long long c, int i);
void			ft_unsimm(const char *str, t_arg *arg, unsigned long long c);
void			ft_unsimnm(const char *str, t_arg *arg, unsigned long long c);
void			ft_octm(const char *str, t_arg *arg, unsigned long long c);
void			ft_octnm(const char *str, t_arg *arg,
				unsigned long long c, int i);
void			ft_float(t_arg *arg, long double i);
void			ft_floatnm(t_arg *arg, long double i);
void			ft_hexm(char *str, t_arg *arg, unsigned long long c);
void			ft_hexnm(char *str, t_arg *arg, unsigned long long c);
void			ft_strm(char *str, t_arg *arg);
void			ft_strnm(char *str, t_arg *arg);
int				display_sign(int i, t_arg *arg, long long c, int len);
void			display_sign_minus(char *str, t_arg *arg, long long c, int len);
void			display_hex(t_arg *arg, unsigned long long c, char *str);
void			display_x_minus(t_arg *arg, char *str, unsigned long long c);
int				int_precision_no_m(const char *str, t_arg *arg,
				int i);
int				int_precision_m(const char *str, t_arg *arg,
				int i);
void			float_no_p(t_arg *arg, char *tmpa, long double i);
void			float_p(char *str, t_arg *arg, long double i);
int				float_len(t_arg *arg, long double i);
void			float_width(int len, t_arg *arg, char *str);
void			float_sign(t_arg *arg);
long double		float_precision(t_arg *arg, long double i, long avant);
long double		is_float_neg(long double i, t_arg *arg);
void			float_no_decimal(t_arg *arg, int flag);
void			print_avant(t_arg *arg, char *str, long double i);
long			convert_my_precision(t_arg *arg);

#endif
