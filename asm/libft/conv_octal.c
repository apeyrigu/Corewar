/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 02:31:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/29 06:23:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		octal_less(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(lst->len_str);
	while (j < lst->len_str_conv)
		tmp[i++] = lst->str_nb[j++];
	while (i < lst->len_str)
		tmp[i++] = ' ';
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		octal_field(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(lst->len_str + 2);
	while (i < lst->len_str + 2)
	{
		if (i < lst->len_str - ((int)ft_strlen(lst->str_nb)))
			tmp[i++] = ' ';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		preci_octal_next(t_print *lst)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->long_preci == -1 &&
			(lst->long_opt > lst->len_str_conv && lst->zero == 1))
		lst->len_str_conv = lst->long_opt;
	tmp = ft_strnew(lst->len_str_conv + 1);
	while (i < lst->len_str_conv)
	{
		if (i < (lst->len_str_conv - (int)ft_strlen(lst->str_nb)))
			tmp[i++] = '0';
		else
			tmp[i++] = lst->str_nb[j++];
	}
	ft_strdel(&lst->str_nb);
	lst->str_nb = tmp;
}

static void		preci_octal(t_print *lst)
{
	if (lst->long_preci == 0 && lst->str_nb[0] == '0' && lst->diez != 1)
	{
		ft_strdel(&lst->str_nb);
		lst->str_nb = ft_strnew(0);
		if (lst->long_opt == 0)
			lst->len_str = 0;
		return ;
	}
	preci_octal_next(lst);
}

void			conv_octal(t_print *lst, va_list ap)
{
	if (lst->h == 1)
	{
		lst->uss_int = va_arg(ap, int);
		lst->usll_int = lst->uss_int;
	}
	else
		recup_arg(lst, ap);
	if (lst->diez == 1 && lst->usll_int > 0)
		lst->str_nb = ft_strjoinfn("0", ft_itoa_base_us(lst->usll_int, 8));
	else
		lst->str_nb = ft_itoa_base_us(lst->usll_int, 8);
	lst->len_str_conv = ft_strlen(lst->str_nb);
	if (lst->long_preci > lst->len_str_conv)
		lst->len_str_conv = lst->long_preci;
	lst->len_str = lst->len_str_conv;
	if (lst->long_opt > lst->len_str)
		lst->len_str = lst->long_opt;
	preci_octal(lst);
	if (lst->less == 1)
		octal_less(lst);
	else
		octal_field(lst);
	lst->str = lst->str_nb;
	lst->len_str_conv = (int)ft_strlen(lst->str);
}
