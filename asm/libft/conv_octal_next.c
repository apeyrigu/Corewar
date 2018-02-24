/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 06:07:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/29 06:21:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		recup_arg(t_print *lst, va_list ap)
{
	if (lst->l == 1 || lst->ll == 1)
	{
		lst->l_int = va_arg(ap, long);
		lst->usll_int = lst->l_int;
	}
	else if (lst->hh == 1)
	{
		lst->us_c = va_arg(ap, int);
		lst->usll_int = lst->us_c;
	}
	else if (lst->j == 1)
	{
		lst->l_int = va_arg(ap, intmax_t);
		lst->usll_int = lst->l_int;
	}
	else if (lst->z == 1)
	{
		lst->size_t_i = va_arg(ap, size_t);
		lst->usll_int = lst->size_t_i;
	}
	else
	{
		lst->us_int = va_arg(ap, int);
		lst->usll_int = lst->us_int;
	}
}
