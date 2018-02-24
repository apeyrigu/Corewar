/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_r_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:39:24 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:39:32 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_r_int(int size, int *tab)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] => ");
		ft_putnbr(tab[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putchar('[');
	ft_putnbr(i);
	ft_putstr("] => (null)\n");
}
