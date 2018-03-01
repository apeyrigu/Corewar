/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:42:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/23 04:12:40 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		conv_u(t_print *lst, va_list ap)
{
	lst->us_int = va_arg(ap, unsigned int);
	lst->str_nb = ft_itoa_long(lst->us_int);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

static void		conv_lu(t_print *lst, va_list ap)
{
	lst->usl_int = va_arg(ap, unsigned long long);
	lst->str_nb = ft_itoa_ulong(lst->usl_int);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

static void		conv_hhu(t_print *lst, va_list ap)
{
	lst->us_c = va_arg(ap, unsigned int);
	lst->str_nb = ft_itoa_long(lst->us_c);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

static void		conv_hu(t_print *lst, va_list ap)
{
	lst->uss_int = va_arg(ap, unsigned int);
	lst->str_nb = ft_itoa_long(lst->uss_int);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void			conv_uint(t_print *lst, va_list ap)
{
	struct lconv		*lc;

	lc = localeconv();
	if (lst->l == 1 || lst->ll == 1 || lst->j == 1 || lst->z == 1)
		conv_lu(lst, ap);
	else if (lst->h == 1)
		conv_hu(lst, ap);
	else if (lst->hh == 1)
		conv_hhu(lst, ap);
	else
		conv_u(lst, ap);
	allocate_str(lst);
	if (lst->plus == 1)
		lst->plus = 0;
	if (lst->space == 1)
		lst->space = 0;
	if (lst->apostrophe == 1 && lc->thousands_sep[0])
	{
		thousands_sep(lst, lc);
		lst->len_str_conv = ft_strlen(lst->str_nb);
	}
}
