/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 01:09:58 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 07:56:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		conv_c_next(t_print *lst)
{
	int		i;

	i = 0;
	if (lst->less == 1)
	{
		lst->str[i++] = lst->c;
		while (i < lst->len_str_conv)
			lst->str[i++] = ' ';
	}
	else if (lst->zero == 1)
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = '0';
		lst->str[i] = lst->c;
	}
	else
	{
		while (i < lst->len_str_conv - 1)
			lst->str[i++] = ' ';
		lst->str[i] = lst->c;
	}
}

static char		*conv_wc(t_print *lst)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (lst->uni_c <= 127)
	{
		lst->c = lst->uni_c;
		conv_c_next(lst);
		return (NULL);
	}
	else
		tmp = ft_itoa_base_unicode(lst->uni_c, 2);
	while (tmp[i])
	{
		if (tmp[i] == 'x')
			tmp[i] = '0';
		i++;
	}
	return (tmp);
}

static void		conv_wc_next(t_print *lst, char *str)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!str)
		return ;
	while (str[i])
	{
		tmp = ft_strsub(str, i, 8);
		lst->str[c++] = ft_btoi(tmp);
		ft_strdel(&tmp);
		i += 8;
		lst->len_str_conv++;
	}
	lst->len_str_conv--;
	ft_strdel(&str);
}

void			conv_c(t_print *lst, va_list ap)
{
	if (lst->l == 1 && MB_CUR_MAX > 1)
		lst->uni_c = va_arg(ap, wchar_t);
	else
		lst->c = va_arg(ap, int);
	lst->len_str_conv = 1;
	if (lst->len_str_conv < lst->long_opt)
		lst->len_str_conv = lst->long_opt;
	lst->str = ft_strnew(lst->len_str_conv);
	if (lst->l == 1 && MB_CUR_MAX > 1)
		conv_wc_next(lst, conv_wc(lst));
	else
		conv_c_next(lst);
}
