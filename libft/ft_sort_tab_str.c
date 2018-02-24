/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:28:50 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:30:51 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_specialcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void		ft_sort_tab_str(int argc, char **argv)
{
	int		j;
	int		k;
	char	*tmp;

	j = argc - 1;
	k = 1;
	while (j >= 1)
	{
		k = 1;
		while (k <= j - 1)
		{
			if (ft_specialcmp(argv[k + 1], argv[k]) < 0)
			{
				tmp = argv[k];
				argv[k] = argv[k + 1];
				argv[k + 1] = tmp;
			}
			k++;
		}
		j--;
	}
}
