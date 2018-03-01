/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:04:58 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 08:49:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		pos(t_print *lst)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (lst->long_preci > lst->len_str_conv)
	{
		tmp = ft_strnew(lst->long_preci);
		while (i < lst->long_preci)
		{
			if (i < (lst->long_preci - lst->len_str_conv))
				tmp[i++] = '0';
			else
				tmp[i++] = lst->str_nb[j++];
		}
		ft_strdel(&lst->str_nb);
		lst->str_nb = tmp;
		lst->len_str_conv = ft_strlen(lst->str_nb);
	}
}

static void		neg(t_print *lst)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (lst->long_preci > lst->len_str_conv)
	{
		tmp = ft_strnew(lst->long_preci);
		while (i < lst->long_preci + 1)
		{
			if (i < ((lst->long_preci) - lst->len_str_conv))
				tmp[i++] = '0';
			else
				tmp[i++] = lst->str_nb[j++];
		}
		ft_strdel(&lst->str_nb);
		lst->str_nb = tmp;
		lst->len_str_conv = ft_strlen(lst->str_nb);
	}
}

void			preci_int(t_print *lst)
{
	if (lst->long_preci == -1)
		return ;
	if (lst->str_nb[0] == '0' && lst->long_preci == 0)
	{
		ft_strdel(&lst->str_nb);
		lst->str_nb = ft_strnew(0);
	}
	else if (lst->neg == 1)
		neg(lst);
	else
		pos(lst);
}
