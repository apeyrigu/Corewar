/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:11:09 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/20 02:06:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit2(char const *s, char c, int range)
{
	char	**tb;
	int		k;
	int		p;
	int		f;

	k = 0;
	p = 0;
	f = 0;
	if (s == NULL || !(tb = (char **)ft_memalloc(sizeof(char *) * range)))
		return (NULL);
	while (s[k] && p < range)
	{
		while (s[k] && s[k] == c)
			k++;
		f = k;
		while (s[f] && s[f] != c)
			f++;
		if (p <= range)
			tb[p] = ft_strsub(s, k, f - k);
		k = f;
		p++;
	}
	return (tb);
}
