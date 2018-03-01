/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 07:07:28 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 09:07:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		options_neg(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (lst->str[is] != '\0')
			str[i++] = lst->str[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	ft_strdel(&lst->str);
	lst->str = ft_strdup(str);
	ft_strdel(&str);
}

static void		options_pos(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(lst->str)))
			str[i++] = lst->str[is++];
		else
			str[i++] = ' ';
	}
	str[i] = '\0';
	ft_strdel(&lst->str);
	lst->str = ft_strdup(str);
	ft_strdel(&str);
}

static void		options_zero(t_print *lst, char *str, int lenght)
{
	int		i;
	int		is;

	i = 0;
	is = 0;
	while (i != lenght)
	{
		if (i >= (lenght - (int)ft_strlen(lst->str)))
			str[i++] = lst->str[is++];
		else
			str[i++] = '0';
	}
	str[i] = '\0';
	ft_strdel(&lst->str);
	lst->str = ft_strdup(str);
	ft_strdel(&str);
}

void			convert_string(t_print *lst)
{
	char	*str;
	int		lenght;

	lenght = lst->long_opt;
	if (lenght < (int)ft_strlen(lst->str))
		lenght = (int)ft_strlen(lst->str);
	str = ft_strnew(lenght);
	if (lst->less == 1)
		options_neg(lst, str, lenght);
	else if (lst->zero == 1)
		options_zero(lst, str, lenght);
	else
		options_pos(lst, str, lenght);
	lst->len_str_conv = (int)ft_strlen(lst->str);
}
