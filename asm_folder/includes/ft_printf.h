/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:13:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/08/28 04:26:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdio.h>
# include <locale.h>
# include <wchar.h>

typedef struct			s_print
{
	int					ind_cut;
	int					len_ret;
	int					neg;
	char				*conv;
	char				*fmt;
	int					plus;
	int					less;
	int					diez;
	int					zero;
	int					space;
	int					apostrophe;
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					bool_star;
	int					got_opt;
	int					long_opt;
	int					long_preci;
	char				*str_nb;
	int					len_str_conv;
	int					len_str;
	char				*str;
	char				c;
	signed char			s_c;
	unsigned char		*us_str;
	unsigned char		us_c;
	long int			l_hexa;
	int					i;
	size_t				size_t_i;
	unsigned int		us_int;
	short				s_int;
	unsigned short		uss_int;
	long int			l_int;
	unsigned long		usl_int;
	unsigned long long	usll_int;
	wchar_t				*uni_str;
	wchar_t				uni_c;
}						t_print;

int						ft_printf(const char *format, ...);
int						ft_sprintf(char **str, const char *format, ...);
int						ft_fprintf(int fd, const char *format, ...);
void					init_opt(t_print *lst);
t_print					*crea_lst(const char *format);

void					core(t_print *lst, va_list ap);

int						verif_format(t_print *lst, va_list ap);
void					recup_format(t_print *lst, va_list ap);

void					spc_flags(t_print *lst, int *i, va_list ap);

void					convert_string(t_print *lst);

void					conv_int(t_print *lst, va_list ap);
void					conv_d(t_print *lst, va_list ap);
void					allocate_str(t_print *lst);
void					thousands_sep(t_print *lst, struct lconv *lc);

void					conv_h(t_print *lst, va_list ap);
void					conv_hh(t_print *lst, va_list ap);
void					conv_l(t_print *lst, va_list ap);
void					conv_j(t_print *lst, va_list ap);
void					conv_z(t_print *lst, va_list ap);

void					preci_int(t_print *lst);

void					field_int(t_print *lst);

void					field_diez(t_print *lst);
void					field_space(t_print *lst);
void					field_zero(t_print *lst);
void					field_plus(t_print *lst);
void					field_less(t_print *lst);

void					conv_c(t_print *lst, va_list ap);

void					conv_s(t_print *lst, va_list ap);

void					preci_string(t_print *lst);

void					conv_octal(t_print *lst, va_list ap);
void					recup_arg(t_print *lst, va_list ap);

void					conv_hexa(t_print *lst, va_list ap);

void					conv_c(t_print *lst, va_list ap);

void					conv_hexa_x(t_print *lst);

void					recup_args_hexa(t_print *lst, va_list ap, int chack);

void					conv_uint(t_print *lst, va_list ap);

void					conv_percent(t_print *lst);

void					conv_bin(t_print*lst, va_list ap);

void					conv_empty(t_print *lst, char c);

void					conv_n(t_print *lst, va_list ap);

int						concaten_result(t_print *lst);

void					chk_color(t_print *lst);

#endif
