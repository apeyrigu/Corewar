/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_int_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:05:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 04:18:31 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	field_less(t_print *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->neg == 1)
		lst->str[i++] = '-';
	else if (lst->plus == 1)
		lst->str[i++] = '+';
	else if (lst->space == 1)
		lst->str[i++] = ' ';
	while (lst->str_nb[j])
		lst->str[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		lst->str[i++] = ' ';
}

void	field_plus(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_conv - 1;
	if (lst->long_preci == 0 && lst->str_nb[0] == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
	else
		lst->str[i--] = '+';
	while (i >= 0)
		lst->str[i--] = ' ';
}

void	field_zero(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_conv - 1;
	if (lst->long_preci == 0 && lst->str_nb[0] == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1 && lst->long_preci != -1)
		lst->str[i--] = '-';
	while (i >= 0 && lst->long_preci > -1)
		lst->str[i--] = ' ';
	while (i >= 0 && lst->long_preci == -1)
		lst->str[i--] = '0';
	if (i < 0)
		i = 0;
	if (lst->long_preci == -1 && lst->neg == 1)
		lst->str[0] = '-';
	else if (lst->plus == 1)
		lst->str[0] = '+';
	else if (lst->space == 1)
		lst->str[0] = ' ';
}

void	field_space(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_conv - 1;
	if (lst->long_preci == 0 && lst->str_nb[0] == 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
	else
		lst->str[i--] = ' ';
	while (i >= 0)
		lst->str[i--] = ' ';
}

void	field_diez(t_print *lst)
{
	int		i;
	int		j;

	i = lst->len_str - 1;
	j = lst->len_str_conv - 1;
	if (lst->long_preci == 0 && lst->str_nb[0] == 0 && lst->long_opt != 0)
		i++;
	while (j >= 0)
		lst->str[i--] = lst->str_nb[j--];
	if (lst->neg == 1)
		lst->str[i--] = '-';
	while (i >= 0)
		lst->str[i--] = ' ';
}
