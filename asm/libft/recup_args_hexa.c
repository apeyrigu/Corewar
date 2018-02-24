/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_args_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 03:06:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 06:53:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	recup_args_hexa(t_print *lst, va_list ap, int check)
{
	if (lst->h == 1)
	{
		lst->uss_int = va_arg(ap, int);
		lst->l_hexa = lst->uss_int;
	}
	else if (lst->hh == 1)
	{
		lst->us_c = va_arg(ap, int);
		lst->l_hexa = lst->us_c;
	}
	else if (lst->l == 1 | lst->ll == 1 || lst->j == 1 || lst->z == 1)
	{
		lst->usll_int = va_arg(ap, unsigned long long);
		lst->l_hexa = lst->usll_int;
	}
	else
	{
		lst->us_int = va_arg(ap, unsigned int);
		lst->l_hexa = lst->us_int;
	}
	if (check == 1)
		lst->str_nb = ft_itoa_base_maj_unsigned(lst->l_hexa, 16);
	else
		lst->str_nb = ft_itoa_base_us(lst->l_hexa, 16);
}
