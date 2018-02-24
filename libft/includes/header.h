/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:01:18 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:20:45 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

typedef unsigned long long t_ull;

typedef struct	s_mdf
{
	int			h;
	int			l;
	int			j;
	int			z;
	int			sum;
}				t_mdf;

typedef struct	s_fmt
{
	char		main;
	t_mdf		*modifier;
	int			minlen;
	int			precision;
	char		*variant;
	int			fmtlen;
}				t_fmt;

typedef struct	s_pair
{
	char		key;
	int			(*f)(t_fmt*, va_list);
}				t_pair;

void			free_fmt(t_fmt *fmt);
int				ft_next_c(const char *restrict str, char c);
char			ft_is_in(char c, char *str);
t_fmt			*new_fmt(char main);
int				ft_putwchar(wchar_t chr);
int				ft_wlen(wchar_t chr);
int				ft_wstrlen(wchar_t *str);
int				ft_putwstr(wchar_t *str, int prc);
int				ft_iwstrlen(wchar_t *str, int prc);
int				ft_count_c(char c, char *str, char not_at_end);
t_mdf			*get_mdf(char *str);
int				get_last_number(char *str, char get_precision, int nbr);
char			ft_not_in_number(int index, char *str);
char			*get_only(char *these, char *str);
t_fmt			*get_fmt(const char *str);
void			print_fmt(t_fmt *fmt);
int				ft_digits(long long k);
int				ft_digits_un(unsigned long long k);
void			ft_putnbr_raw(long long n, int precision);
void			ft_unsigned_raw(unsigned long long n, int precision);
char			disp_signe(double data, t_fmt *fmt, char testmode);
char			disp_signe_un(t_ull data, t_fmt *fmt, char testmode);
int				disp_padding_int(int padding, t_fmt *fmt, long long data);
int				disp_padding_inv(int padding, t_fmt *fmt, long long data);
int				disp_padding_c(int padding, t_fmt *fmt, unsigned char data);
int				p_char(t_fmt *fmt, va_list list);
int				p_wchar(t_fmt *fmt, va_list list);
int				p_ptr(t_fmt *fmt, va_list list);
int				disp_padding_ws(wchar_t *str, t_fmt *fmt);
int				p_wstring(t_fmt *fmt, va_list list);
int				p_percent(t_fmt *fmt, va_list list);
int				p_integer(t_fmt *fmt, va_list list);
int				p_unsigned(t_fmt *fmt, va_list list);
int				ft_digits_oc(unsigned long long k);
int				disp_padding_oc(int padding, t_fmt *fmt, t_ull data);
void			ft_octal_raw(t_ull n, int precision, t_fmt *fmt);
int				p_octal(t_fmt *fmt, va_list list);
int				p_lhexa(t_fmt *fmt, va_list list);
int				p_longhexa(t_fmt *fmt, va_list list);
int				ft_digits_hx(unsigned long long k);
int				disp_padding_hx(int padding, t_fmt *fmt, t_ull data);
char			ft_to_hx(int k, char maj);
void			ft_hexa_raw(unsigned long long n, int precision, char maj);
int				p_hexa(t_fmt *fmt, va_list list);
int				p_invalid(t_fmt *fmt);
int				ft_digits_lhx(unsigned long k);
int				disp_padding_lhx(int padding, t_fmt *fmt, unsigned long data);
int				disp_zerox(char c);
void			ft_lhexa_raw(unsigned long n, int precision, char maj);
int				p_lhexa(t_fmt *fmt, va_list list);
int				ft_putstr_c(const char *str, int precision);
int				p_string(t_fmt *fmt, va_list list);
int				p_long(t_fmt *fmt, va_list list);
int				p_ulong(t_fmt *fmt, va_list list);
int				print_wfmt(t_fmt *fmt, va_list list);
long long		get_arg(t_fmt *fmt, va_list list);
t_ull			get_unsigned_arg(t_fmt *fmt, va_list list);
int				ft_printf(const char *restrict format, ...);
#endif
