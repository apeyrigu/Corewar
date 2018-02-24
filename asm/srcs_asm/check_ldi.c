/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 02:22:32 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/01 02:25:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	check_ldi_reg(t_env *env, char **tab)
{
	if (is_dir(env, tab[1]))
	{
		if (is_reg(tab[2]))
		{
			env->champ_size += 6;
			return (1);
		}
	}
	else if (is_reg(tab[1]))
		if (is_reg(tab[2]))
		{
			env->champ_size += 5;
			return (1);
		}
	return (0);
}

char	check_ldi_ind(t_env *env, char **tab)
{
	if (is_dir(env, tab[1]))
	{
		if (is_reg(tab[2]))
		{
			env->champ_size += 7;
			return (1);
		}
	}
	else if (is_reg(tab[1]))
		if (is_reg(tab[2]))
		{
			env->champ_size += 6;
			return (1);
		}
	return (0);
}

char	check_ldi_dir(t_env *env, char **tab)
{
	if (is_dir(env, tab[1]))
	{
		if (is_reg(tab[2]))
		{
			env->champ_size += 7;
			return (1);
		}
	}
	else if (is_reg(tab[1]))
		if (is_reg(tab[2]))
		{
			env->champ_size += 6;
			return (1);
		}
	return (0);
}

char	check_ldi(t_env *env, char **tab)
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
		return (check_ldi_reg(env, tab));
	else if (is_ind(env, tab[0]))
		return (check_ldi_ind(env, tab));
	else if (is_dir(env, tab[0]))
		return (check_ldi_dir(env, tab));
	return (0);
}
