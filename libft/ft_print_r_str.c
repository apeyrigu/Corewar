/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_r_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:33:33 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:33:48 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_r_str(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putchar('[');
		ft_putnbr(i);
		ft_putstr("] => |");
		ft_putstr(tab[i]);
		ft_putstr("|\n");
		i++;
	}
	ft_putchar('[');
	ft_putnbr(i);
	ft_putstr("] => (null)\n");
}
