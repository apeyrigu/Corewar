/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 05:29:23 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/01 01:20:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char			is_dir(t_env *env, const char *str)
{
	if (!((*str == DIRECT_CHAR) ? str++ : 0))
		return (0);
	if (*str == '-')
	{
		str++;
		if (*str == LABEL_CHAR)
			return (0);
	}
	if (*str >= '0' && *str <= '9')
	{
		while (*str && (*str >= '0' && *str <= '9'))
			str++;
		while (*str && *str < 33)
			str++;
		if (*str && (*str != COMMENT_CHAR && *str != ';'))
			return (0);
		return (1);
	}
	else if (*str == LABEL_CHAR)
	{
		if (!save_ulabel(env, &str[1]))
			return (0);
		return (1);
	}
	return (0);
}

char			is_ind(t_env *env, const char *str)
{
	if (*str == '-')
	{
		str++;
		if (*str == LABEL_CHAR)
			return (0);
	}
	if (*str >= '0' && *str <= '9')
	{
		while (*str && (*str >= '0' && *str <= '9'))
			str++;
		while (*str && *str < 33)
			str++;
		if (*str && (*str != COMMENT_CHAR && *str != ';'))
			return (0);
		return (1);
	}
	else if (*str == LABEL_CHAR)
	{
		if (!save_ulabel(env, &str[1]))
			return (0);
		return (1);
	}
	return (0);
}

char			is_reg(const char *str)
{
	int		reg;

	while (*str && *str != 'r')
		str++;
	if (!*str)
		return (0);
	str++;
	if (*str < '0' || *str > '9')
		return (0);
	reg = ft_atoi(str);
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (1);
}

char			check_ld(t_env *env, char **tab)
{
	if (!tab[0] || !tab[1])
		return (0);
	while (*tab[0] < 33)
		tab[0]++;
	while (*tab[1] < 33)
		tab[1]++;
	if (tab[0][0] == DIRECT_CHAR && is_dir(env, tab[0]))
	{
		if (is_reg(tab[1]))
		{
			env->champ_size += 7;
			return (1);
		}
	}
	else if (is_ind(env, tab[0]))
		if (is_reg(tab[1]))
		{
			env->champ_size += 5;
			return (1);
		}
	return (0);
}
