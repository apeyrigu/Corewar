/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 04:40:10 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/01 01:15:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char		get_op10(t_env *env, const char *str, char **tab)
{
	if (str[0] == 'l' && str[1] == 'd' && str[2] == 'i' && (str[3] < 33 ||
				str[3] == DIRECT_CHAR || str[3] == LABEL_CHAR))
	{
		str += 3;
		while (*str && *str != LABEL_CHAR && (*str < '0' || *str > '9') &&
				*str != '-' && *str != DIRECT_CHAR && *str != 'r')
			str++;
		tab = ft_strsplit2(str, SEPARATOR_CHAR, 3);
		env->save[0] = tab[0];
		env->save[1] = tab[1];
		env->save[2] = tab[2];
		if (!check_ldi(env, tab))
		{
			free_tab(env->save, tab, 3);
			return (0);
		}
		free_tab(env->save, tab, 3);
		return (1);
	}
	return (get_op11(env, str, tab));
}

static char		get_op9(t_env *env, const char *str, char **tab)
{
	if (str[0] == 'z' && str[1] == 'j' && str[2] == 'm' && str[3] == 'p' &&
			(str[4] < 33 || str[4] == DIRECT_CHAR))
	{
		while (*str && *str != DIRECT_CHAR)
			str++;
		if (!is_dir(env, str))
			return (0);
		env->champ_size += 3;
		return (1);
	}
	return (get_op10(env, str, tab));
}

static char		get_op8(t_env *env, const char *str, char **tab)
{
	if (str[0] == 'x' && str[1] == 'o' && str[2] == 'r' && (str[3] < 33 ||
				str[3] == DIRECT_CHAR || str[3] == LABEL_CHAR))
	{
		str += 3;
		while (*str && *str != LABEL_CHAR && (*str < '0' || *str > '9') &&
				*str != '-' && *str != DIRECT_CHAR && *str != 'r')
			str++;
		tab = ft_strsplit2(str, SEPARATOR_CHAR, 3);
		env->save[0] = tab[0];
		env->save[1] = tab[1];
		env->save[2] = tab[2];
		if (!check_and(env, tab))
		{
			free_tab(env->save, tab, 3);
			return (0);
		}
		free_tab(env->save, tab, 3);
		return (1);
	}
	return (get_op9(env, str, tab));
}

static char		get_op7(t_env *env, const char *str, char **tab)
{
	if (str[0] == 'o' && str[1] == 'r' && (str[2] < 33 || str[2] == DIRECT_CHAR
				|| str[2] == LABEL_CHAR))
	{
		str += 2;
		while (*str && *str != LABEL_CHAR && (*str < '0' || *str > '9') &&
				*str != '-' && *str != DIRECT_CHAR && *str != 'r')
			str++;
		tab = ft_strsplit2(str, SEPARATOR_CHAR, 3);
		env->save[0] = tab[0];
		env->save[1] = tab[1];
		env->save[2] = tab[2];
		if (!check_and(env, tab))
		{
			free_tab(env->save, tab, 3);
			return (0);
		}
		free_tab(env->save, tab, 3);
		return (1);
	}
	return (get_op8(env, str, tab));
}

char			get_op6(t_env *env, const char *str, char **tab)
{
	if (str[0] == 'a' && str[1] == 'n' && str[2] == 'd' && (str[3] < 33 ||
				str[3] == DIRECT_CHAR || str[3] == LABEL_CHAR))
	{
		str += 3;
		while (*str && *str != LABEL_CHAR && (*str < '0' || *str > '9') &&
				*str != '-' && *str != DIRECT_CHAR && *str != 'r')
			str++;
		tab = ft_strsplit2(str, SEPARATOR_CHAR, 3);
		env->save[0] = tab[0];
		env->save[1] = tab[1];
		env->save[2] = tab[2];
		if (!check_and(env, tab))
		{
			free_tab(env->save, tab, 3);
			return (0);
		}
		free_tab(env->save, tab, 3);
		return (1);
	}
	return (get_op7(env, str, tab));
}
