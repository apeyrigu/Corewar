/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 02:07:23 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/29 05:05:08 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		recup_opt(t_print *lst, int i)
{
	if (lst->conv[i] == '+')
		lst->plus = 1;
	if (lst->conv[i] == '-')
		lst->less = 1;
	if (lst->conv[i] == '#')
		lst->diez = 1;
	if ((lst->conv[i] == '0' && i == 0) || (lst->conv[i] == '0' &&
			!(lst->conv[i - 1] > '0' && lst->conv[i - 1] <= '9')))
		lst->zero = 1;
	if (lst->conv[i] == ' ')
		lst->space = 1;
	if (lst->conv[i] == '\'')
		lst->apostrophe = 1;
	if (lst->plus == 1 && lst->space == 1)
		lst->space = 0;
	if (lst->less == 1 && lst->zero == 1)
		lst->zero = 0;
}

static void		lenght_field(t_print *lst, int *i)
{
	lst->long_opt = ((int)lst->conv[(*i)++] - 48);
	while (lst->conv[(*i)] >= 48 && lst->conv[(*i)] <= 57)
	{
		lst->long_opt *= 10;
		lst->long_opt += ((int)lst->conv[(*i)++] - 48);
	}
}

static void		recup_preci(t_print *lst, int *i)
{
	int		tmp;

	(*i)++;
	tmp = 0;
	if (lst->long_preci == -1)
		lst->long_preci++;
	while (lst->conv[(*i)] >= 48 && lst->conv[(*i)] <= 57)
	{
		tmp *= 10;
		tmp += ((int)lst->conv[(*i)++] - 48);
	}
	if (lst->bool_star == 1 && lst->long_preci < tmp)
		lst->long_preci = tmp;
	else if (lst->bool_star == 0)
		lst->long_preci = tmp;
}

static void		recup_flag(t_print *lst, int *i)
{
	if (lst->conv[*i] == 'h' && lst->conv[*i + 1] == 'h')
	{
		lst->hh = 1;
		(*i)++;
	}
	else if (lst->conv[*i] == 'h')
		lst->h = 1;
	else if (lst->conv[*i] == 'l' && lst->conv[*i + 1] == 'l')
	{
		lst->ll = 1;
		(*i)++;
	}
	else if (lst->conv[*i] == 'l')
		lst->l = 1;
	else if (lst->conv[*i] == 'j')
		lst->j = 1;
	else if (lst->conv[*i] == 'z')
		lst->z = 1;
}

void			recup_format(t_print *lst, va_list ap)
{
	int		i;

	i = 0;
	while (lst->conv[i])
	{
		if (lst->conv[i] > 48 && lst->conv[i] < 58 && lst->long_preci == -1)
			lenght_field(lst, &i);
		if (lst->conv[i] == '-' || lst->conv[i] == '+' || lst->conv[i] == '#'
				|| lst->conv[i] == '0' || lst->conv[i] == ' ' ||
				lst->conv[i] == '\'')
			recup_opt(lst, i);
		if (lst->conv[i] > 48 && lst->conv[i] < 58 && lst->long_preci == -1)
			lenght_field(lst, &i);
		if (lst->conv[i] == '.')
			recup_preci(lst, &i);
		if (lst->conv[i] == 'h' || lst->conv[i] == 'l' || lst->conv[i] == 'j' ||
				lst->conv[i] == 'z')
			recup_flag(lst, &i);
		else
			spc_flags(lst, &i, ap);
		i++;
	}
}
