/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concaten_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 04:22:49 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 02:05:05 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*str_cut(char *str, int ind)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	tmp = ft_strnew(ind + 1);
	while (i < ind)
		tmp[j++] = str[i++];
	return (tmp);
}

static char		*str_join(char *str1, char *str2, int ind1, int ind2)
{
	int		i;
	int		j;
	int		c;
	char	*tmp;

	i = 0;
	j = 0;
	c = 0;
	tmp = ft_strnew(ind1 + ind2);
	while (i < ind1)
		tmp[c++] = str1[i++];
	while (j < ind2)
		tmp[c++] = str2[j++];
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (tmp);
}

static char		*str_join_fin(char *str1, char *str2, int ind, int len)
{
	int		i;
	int		j;
	int		c;
	char	*tmp;

	i = 0;
	j = 0;
	c = 0;
	tmp = ft_strnew(ind + (int)ft_strlen(str2));
	while (i < ind)
		tmp[c++] = str1[i++];
	while (str2[len])
		tmp[c++] = str2[len++];
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (tmp);
}

int				concaten_result(t_print *lst)
{
	char	*tmp;
	int		len_conv;
	int		i;

	i = 0;
	tmp = NULL;
	len_conv = (int)ft_strlen(lst->conv);
	tmp = str_cut(lst->fmt, lst->ind_cut);
	tmp = str_join(tmp, lst->str, lst->ind_cut, lst->len_str_conv);
	i = lst->ind_cut + lst->len_str_conv;
	lst->fmt = str_join_fin(tmp, lst->fmt, i, lst->ind_cut + len_conv + 1);
	lst->len_ret = lst->ind_cut + lst->len_str_conv;
	return (i - 1);
}
