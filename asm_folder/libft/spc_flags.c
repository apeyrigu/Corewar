/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:57:14 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/21 17:56:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	spc_flags(t_print *lst, int *i, va_list ap)
{
	if (lst->conv[(*i)] == '*')
	{
		lst->bool_star = 1;
		if (i > 0 && lst->conv[(*i) - 1] == '.')
		{
			lst->long_preci = va_arg(ap, int);
			if (lst->long_preci < 0)
				lst->long_preci = -1;
		}
		else
		{
			lst->long_opt = va_arg(ap, int);
			if (lst->long_opt < 0)
			{
				lst->long_opt *= -1;
				lst->less = 1;
			}
		}
	}
}
