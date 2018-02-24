/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:25:45 by abassibe          #+#    #+#             */
/*   Updated: 2017/04/28 03:41:56 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conv_h(t_print *lst, va_list ap)
{
	unsigned long long	nb;

	lst->s_int = va_arg(ap, int);
	nb = lst->s_int;
	if (lst->s_int < 0)
	{
		lst->neg = 1;
		nb = (long long)(lst->s_int) * -1;
	}
	lst->str_nb = ft_itoa_long(nb);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void	conv_hh(t_print *lst, va_list ap)
{
	unsigned long long	nb;

	lst->c = va_arg(ap, int);
	nb = (int)lst->c;
	if ((int)lst->c < 0)
	{
		lst->neg = 1;
		nb = (long long)(lst->c) * -1;
	}
	lst->str_nb = ft_itoa_long(nb);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void	conv_l(t_print *lst, va_list ap)
{
	long long	nb;

	lst->l_int = va_arg(ap, long);
	nb = lst->l_int;
	if (nb < -9223372036854775807)
	{
		lst->str_nb = ft_strdup("9223372036854775808");
		lst->neg = 1;
	}
	else
	{
		if (lst->l_int < 0)
		{
			lst->neg = 1;
			nb = (long long)(lst->l_int) * -1;
		}
		lst->str_nb = ft_itoa_long(nb);
	}
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void	conv_j(t_print *lst, va_list ap)
{
	unsigned long long	nb;

	lst->l_int = va_arg(ap, intmax_t);
	nb = lst->l_int;
	if (lst->l_int < -9223372036854775807)
	{
		lst->str_nb = ft_strdup("9223372036854775808");
		lst->neg = 1;
	}
	else
	{
		if (lst->l_int < 0)
		{
			lst->neg = 1;
			nb = (long long)(lst->l_int) * -1;
		}
		lst->str_nb = ft_itoa_long(nb);
	}
	lst->len_str_conv = ft_strlen(lst->str_nb);
}

void	conv_z(t_print *lst, va_list ap)
{
	lst->size_t_i = va_arg(ap, size_t);
	lst->str_nb = ft_itoa_long(lst->size_t_i);
	lst->len_str_conv = ft_strlen(lst->str_nb);
}
