/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 01:21:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/29 05:30:54 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	preci_string(t_print *lst)
{
	char	*str;
	int		i;

	i = 0;
	if (lst->long_preci == -1)
		return ;
	str = ft_strnew(lst->long_preci + 1);
	while (i < lst->long_preci)
	{
		str[i] = lst->str[i];
		i++;
	}
	ft_strdel(&lst->str);
	lst->str = ft_strdup(str);
	ft_strdel(&str);
}
