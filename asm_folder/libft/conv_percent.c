/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:09:36 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/24 15:48:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_percent(t_print *lst)
{
	int		i;

	i = 0;
	lst->len_str_conv = 1;
	if (lst->long_opt > lst->len_str_conv)
		lst->len_str_conv = lst->long_opt;
	lst->str = ft_strnew(lst->len_str_conv);
	if (lst->less == 1)
	{
		lst->str[i++] = '%';
		while (i < lst->len_str_conv)
			lst->str[i++] = ' ';
	}
	else if (lst->zero == 1)
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = '0';
		lst->str[lst->len_str_conv - 1] = '%';
	}
	else
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = ' ';
		lst->str[lst->len_str_conv - 1] = '%';
	}
}
