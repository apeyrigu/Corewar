/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:17:12 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/01 02:21:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	check_sti_dir(t_env *env, char **tab)
{
	if (is_dir(env, tab[2]))
	{
		env->champ_size += 7;
		return (1);
	}
	else if (is_reg(tab[2]))
	{
		env->champ_size += 6;
		return (1);
	}
	return (0);
}

char	check_sti_ind(t_env *env, char **tab)
{
	if (is_dir(env, tab[2]))
	{
		env->champ_size += 7;
		return (1);
	}
	else if (is_reg(tab[2]))
	{
		env->champ_size += 6;
		return (1);
	}
	return (0);
}

char	check_sti_reg(t_env *env, char **tab)
{
	if (is_dir(env, tab[2]))
	{
		env->champ_size += 6;
		return (1);
	}
	else if (is_reg(tab[2]))
	{
		env->champ_size += 5;
		return (1);
	}
	return (0);
}

char	check_sti(t_env *env, char **tab)
{
	if (!tab[0] || !tab[1] || !tab[2])
		return (0);
	while (*tab[0] < 33)
		tab[0]++;
	while (*tab[1] < 33)
		tab[1]++;
	while (*tab[2] < 33)
		tab[2]++;
	if (is_reg(tab[0]))
	{
		if (is_dir(env, tab[1]))
			return (check_sti_dir(env, tab));
		else if (is_ind(env, tab[1]))
			return (check_sti_ind(env, tab));
		else if (is_reg(tab[1]))
			return (check_sti_reg(env, tab));
	}
	return (0);
}
