/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 03:20:50 by abassibe          #+#    #+#             */
/*   Updated: 2017/05/02 12:42:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print			*crea_lst(const char *format)
{
	t_print		*new;

	new = (t_print *)malloc(sizeof(t_print));
	new->fmt = NULL;
	new->fmt = ft_strdup((char *)format);
	return (new);
}

static void		init_opt_next(t_print *lst)
{
	lst->long_preci = -1;
	lst->neg = 0;
	lst->str = NULL;
	lst->len_str = 0;
	lst->conv = NULL;
	lst->s_c = 0;
	lst->us_str = NULL;
	lst->us_c = 0;
	lst->l_hexa = 0;
	lst->i = 0;
	lst->usl_int = 0;
	lst->uni_str = NULL;
	lst->uni_c = 0;
	lst->bool_star = 0;
	lst->apostrophe = 0;
}

void			init_opt(t_print *lst)
{
	lst->h = 0;
	lst->hh = 0;
	lst->l = 0;
	lst->ll = 0;
	lst->j = 0;
	lst->z = 0;
	lst->plus = 0;
	lst->less = 0;
	lst->diez = 0;
	lst->zero = 0;
	lst->space = 0;
	lst->got_opt = 0;
	lst->long_opt = 0;
	lst->c = 0;
	lst->s_int = 0;
	lst->uss_int = 0;
	lst->us_int = 0;
	lst->us_c = 0;
	lst->usll_int = 0;
	lst->l_int = 0;
	lst->size_t_i = 0;
	lst->str_nb = NULL;
	lst->len_str_conv = 0;
	init_opt_next(lst);
}
