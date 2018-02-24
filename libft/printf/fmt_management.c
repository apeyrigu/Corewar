/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:22:09 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:17:55 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_fmt	*new_fmt(char main)
{
	t_fmt			*ret;

	ret = (t_fmt*)malloc(sizeof(t_fmt));
	ret->main = main;
	ret->precision = -1;
	ret->minlen = -1;
	ret->modifier = NULL;
	return (ret);
}

void	free_fmt(t_fmt *fmt)
{
	if (!fmt)
		return ;
	if (fmt->modifier)
		free(fmt->modifier);
	if (fmt->variant)
		free(fmt->variant);
	free(fmt);
}

t_fmt	*kill_upper(t_fmt *fmt)
{
	if (ft_is_in(fmt->main, "SDOUC"))
	{
		fmt->main = ft_tolower(fmt->main);
		fmt->modifier->l += 1;
		fmt->modifier->sum += 1;
	}
	return (fmt);
}

t_fmt	*get_fmt(const char *str)
{
	unsigned long	i;
	t_fmt			*ret;
	char			*bck;

	ret = new_fmt('!');
	i = 1;
	while (ft_is_in(str[i], "0123456789#-+ .hljz"))
		i++;
	bck = ft_strsub(str, 0, i + 1);
	ret->main = str[i];
	ret->precision = get_last_number(bck, 1, 0);
	if (ret->precision == -1 && ft_is_in('.', bck))
		ret->precision = 0;
	ret->minlen = get_last_number(bck, 0, 0);
	ret->modifier = get_mdf(bck);
	ret->variant = get_only("#0-+ ", bck);
	ret->fmtlen = ft_strlen(bck) - 1;
	free(bck);
	return (kill_upper(ret));
}
