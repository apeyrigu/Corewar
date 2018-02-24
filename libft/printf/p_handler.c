/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:19:38 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 02:24:36 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		p_ptr(t_fmt *fmt, va_list list)
{
	int written;

	written = 0;
	written += p_lhexa(fmt, list);
	return (written);
}

int		d_lx(unsigned long k)
{
	int i;

	i = 0;
	if (k == 0)
		return (1);
	while (k != 0)
	{
		k /= 16;
		i++;
	}
	return (i);
}

int		disp_padding_lhx(int padding, t_fmt *fmt, unsigned long data)
{
	char	c;
	int		pc;

	pc = 0;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant) &&
	((fmt->precision == -1) ? 2147483647 : fmt->precision) > fmt->minlen)
		c = '0';
	else
		c = ' ';
	if (fmt->precision >= d_lx(data))
		pc = (fmt->precision - d_lx(data));
	while (padding + pc + d_lx(data) < fmt->minlen)
	{
		write(1, &c, 1);
		padding++;
	}
	return (padding);
}

void	ft_lhexa_raw(unsigned long n, int precis, char maj)
{
	unsigned	i;
	int			nb_d;
	char		ptr[d_lx(n) + 1];

	if (precis == 0)
		return ;
	ptr[d_lx(n)] = '\0';
	nb_d = d_lx(n);
	if (n == 0)
		ft_strcpy(ptr, "0");
	else
	{
		i = 0;
		while (n != 0)
		{
			ptr[nb_d - i - 1] = ft_to_hx(n % 16, maj);
			n /= 16;
			i++;
		}
	}
	i = 0;
	while ((unsigned)nb_d + (i++) < (unsigned)((precis == -1) ? 0 : precis))
		write(1, "0", 1);
	ft_putstr(ptr);
}

int		p_lhexa(t_fmt *fmt, va_list list)
{
	int				padding;
	unsigned long	data;
	int				written;

	written = 0;
	data = va_arg(list, unsigned long);
	written += (padding = disp_signe_un(data, fmt, 1));
	if (ft_is_in('-', fmt->variant))
	{
		disp_zerox('a');
		ft_lhexa_raw(data, fmt->precision, (fmt->main == 'X'));
	}
	if (ft_is_in('0', fmt->variant))
		disp_zerox('a');
	written += disp_padding_lhx(padding + 2, fmt, data) - padding;
	if (!ft_is_in('-', fmt->variant))
	{
		if (!ft_is_in('0', fmt->variant))
			disp_zerox('a');
		ft_lhexa_raw(data, fmt->precision, (fmt->main == 'X'));
	}
	if (fmt->precision != 0)
		written += (fmt->precision > d_lx(data)) ? fmt->precision : d_lx(data);
	return (written);
}
