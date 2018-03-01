/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoisson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:45:38 by apoisson          #+#    #+#             */
/*   Updated: 2018/02/06 03:43:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_word(const char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c)
			word++;
		if (s[i] != c && s[i + 1] == '\0')
			word++;
		i++;
	}
	return (word);
}

static char	*ft_add_word_tab(const char *s, char c, int *i)
{
	int		j;
	char	*str;
	char	*tmp;

	j = *i;
	while (s[*i] && s[*i] != c)
		*i = *i + 1;
	tmp = ft_strsub(s, j, *i - j);
	str = ft_strdup(tmp);
	ft_strdel(&tmp);
	while (s[*i] == c)
		*i = *i + 1;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			word;
	char		**tab;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	word = ft_count_word(s, c);
	if (!(tab = (char**)malloc(sizeof(tab) * (word + 1))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (j < word && s[i])
	{
		tab[j] = ft_add_word_tab(s, c, &i);
		j++;
	}
	tab[j] = 0;
	return (tab);
}
