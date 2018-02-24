/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:21:58 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:26:19 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		disp_padding_inv(int padding, t_fmt *fmt, long long data)
{
	char c;

	data++;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant))
		c = '0';
	else
		c = ' ';
	while (padding + 1 < fmt->minlen)
	{
		write(1, &c, 1);
		padding++;
	}
	return (padding);
}

void	ft_putchar_prec(t_fmt *fmt)
{
	write(1, &(fmt->main), 1);
}

int		p_invalid(t_fmt *fmt)
{
	int			padding;
	long long	data;
	int			written;

	written = 0;
	padding = 0;
	data = fmt->main;
	if (ft_is_in('-', fmt->variant))
		ft_putchar_prec(fmt);
	written += disp_padding_inv(padding, fmt, data) - padding;
	if (!ft_is_in('-', fmt->variant))
		ft_putchar_prec(fmt);
	if (fmt->main)
		written += 1;
	return (written);
}
