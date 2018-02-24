/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 02:38:34 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/30 22:31:08 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"
#include "pairs.h"

int	print_wfmt(t_fmt *fmt, va_list list)
{
	int i;

	i = 0;
	while ((g_pairs[i]).key != '@')
	{
		if (fmt->main == (g_pairs[i]).key)
			return ((g_pairs[i]).f(fmt, list));
		i++;
	}
	return (p_invalid(fmt));
}

int	ft_printf(const char *restrict format, ...)
{
	int				i;
	int				written;
	unsigned long	strpos;
	va_list			list;
	t_fmt			*fnow;

	strpos = 0;
	va_start(list, format);
	i = 0;
	written = 0;
	while (i++ < ft_count_c('%', (char*)format, 1))
	{
		write(1, &(format[strpos]), ft_next_c(&(format[strpos]), '%'));
		written += ft_next_c(&(format[strpos]), '%');
		strpos += ft_next_c(&(format[strpos]), '%');
		fnow = get_fmt(&(format[strpos]));
		i += (fnow->main == '%') ? 1 : 0;
		written += print_wfmt(fnow, list);
		strpos += fnow->fmtlen + 1;
		free_fmt(fnow);
	}
	write(1, &(format[strpos]), ft_next_c(&(format[strpos]), '%'));
	written += ft_next_c(&(format[strpos]), '%');
	return (written);
}
