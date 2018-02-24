/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 16:54:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/06/10 00:19:45 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*set_tab_one(int i)
{
	static char		*tab1[11];

	tab1[0] = "eoc}";
	tab1[1] = "bold}";
	tab1[2] = "ita}";
	tab1[3] = "und}";
	tab1[4] = "light}";
	tab1[5] = "red}";
	tab1[6] = "green}";
	tab1[7] = "yellow}";
	tab1[8] = "blue}";
	tab1[9] = "purple}";
	tab1[10] = "cyan}";
	return (tab1[i]);
}

static char		*set_tab_two(int i)
{
	static char		*tab2[11];

	tab2[0] = "\033[0;0m";
	tab2[1] = "\033[0;1m";
	tab2[2] = "\033[0;3m";
	tab2[3] = "\033[0;4m";
	tab2[4] = "\033[0;7m";
	tab2[5] = "\033[0;031m";
	tab2[6] = "\033[0;32m";
	tab2[7] = "\033[0;33m";
	tab2[8] = "\033[0;34m";
	tab2[9] = "\033[0;35m";
	tab2[10] = "\033[0;36m";
	return (tab2[i]);
}

static int		set_tab(t_print *lst, char *str, int ind)
{
	int				i;

	i = 0;
	while (i <= 10)
	{
		if (!(ft_strcmp(str, set_tab_one(i))))
		{
			lst->str = ft_strdup(set_tab_two(i));
			lst->len_str_conv = (int)ft_strlen(set_tab_two(i));
			lst->conv = ft_strdup(str);
			lst->ind_cut = ind;
			lst->bool_star = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void			chk_color(t_print *lst)
{
	int				i;
	int				j;
	int				c;
	char			*tmp;

	i = -1;
	j = -1;
	c = 0;
	tmp = NULL;
	while (lst->fmt[++i] && lst->fmt[++j])
		if (lst->fmt[i] == '{')
		{
			tmp = ft_strnew(10);
			j = i + 1;
			while (lst->fmt[j] && lst->fmt[j] != '}' && c < 10)
				tmp[c++] = lst->fmt[j++];
			tmp[c++] = lst->fmt[j++];
			if (set_tab(lst, tmp, i))
				i = concaten_result(lst);
			j = 0;
			c = 0;
		}
	if (lst->bool_star == 1)
		lst->len_ret += j;
	ft_strdel(&tmp);
}
