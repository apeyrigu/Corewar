/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:05:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 08:26:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	field_int(t_print *lst)
{
	if (lst->len_str <= lst->len_str_conv &&
			(lst->neg == 1 || lst->space == 1 || lst->plus == 1))
		lst->len_str++;
	if (lst->zero == 1)
		field_zero(lst);
	else if (lst->space == 1)
		field_space(lst);
	else if (lst->less == 1)
		field_less(lst);
	else if (lst->plus == 1)
		field_plus(lst);
	else
		field_diez(lst);
	lst->len_str_conv = ft_strlen(lst->str);
	ft_strdel(&lst->str_nb);
}
