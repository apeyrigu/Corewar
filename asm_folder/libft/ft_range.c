/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:04:28 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/03 04:18:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_range(int min, int max)
{
	int *tab;
	int c;

	c = 0;
	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * (max - min))))
		return (NULL);
	while (min < max)
	{
		tab[c] = min;
		min++;
		c++;
	}
	return (tab);
	free(tab);
}
