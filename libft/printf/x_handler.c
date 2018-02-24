/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 04:23:05 by pcluchet          #+#    #+#             */
/*   Updated: 2017/01/31 04:28:00 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		di_h(unsigned long long k)
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

int		disp_padding_hx(int padding, t_fmt *fmt, unsigned long long dta)
{
	char	c;
	int		pc;

	pc = 0;
	if (ft_is_in('0', fmt->variant) && !ft_is_in('-', fmt->variant) &&
	((fmt->precision == -1) ? 2147483647 : fmt->precision) > fmt->minlen)
		c = '0';
	else
		c = ' ';
	if (fmt->precision >= di_h(dta))
		pc = (fmt->precision - di_h(dta));
	if (fmt->precision == 0 && !dta)
		pc -= ft_digits(dta);
	while (padding + pc + di_h(dta) < fmt->minlen)
	{
		write(1, &c, 1);
		padding++;
	}
	return (padding);
}

void	ft_hexa_raw(unsigned long long n, int precis, char maj)
{
	unsigned	i;
	int			nb_d;
	char		ptr[di_h(n) + 1];

	if (precis == 0 && !n)
		return ;
	ptr[di_h(n)] = '\0';
	nb_d = di_h(n);
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

int		p_hexa(t_fmt *fmt, va_list list)
{
	int					padding;
	unsigned long long	dta;
	int					w;

	w = 0;
	dta = get_unsigned_arg(fmt, list);
	padding = (ft_is_in('#', fmt->variant) && dta) ? 2 : 0;
	if (ft_is_in('-', fmt->variant))
	{
		w += (ft_is_in('#', fmt->variant) && dta) ? disp_zerox(fmt->main) : 0;
		ft_hexa_raw(dta, fmt->precision, (fmt->main == 'X'));
	}
	if (ft_is_in('0', fmt->variant) && ft_is_in('#', fmt->variant) &&
			dta && !ft_is_in('-', fmt->variant))
		w += disp_zerox(fmt->main);
	w += disp_padding_hx(padding, fmt, dta) - padding;
	if (!ft_is_in('-', fmt->variant))
	{
		if (!ft_is_in('0', fmt->variant) && ft_is_in('#', fmt->variant) && dta)
			w += disp_zerox(fmt->main);
		ft_hexa_raw(dta, fmt->precision, (fmt->main == 'X'));
	}
	if (!(!fmt->precision && !dta))
		w += (fmt->precision > di_h(dta)) ? fmt->precision : di_h(dta);
	return (w);
}

int		disp_zerox(char c)
{
	if (!ft_isupper(c))
		write(1, "0x", 2);
	else
		write(1, "0X", 2);
	return (2);
}
