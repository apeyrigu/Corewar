/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:22:40 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 20:19:43 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	p_percent(t_fmt *fmt, va_list list)
{
	int				padding;
	long long		data;
	int				written;

	list++;
	written = 0;
	padding = 0;
	data = fmt->main;
	if (ft_is_in('-', fmt->variant))
		write(1, &fmt->main, 1);
	written += disp_padding_inv(padding, fmt, data) - padding;
	if (!ft_is_in('-', fmt->variant))
		write(1, &fmt->main, 1);
	written += 1;
	return (written);
}
