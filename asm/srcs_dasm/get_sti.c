/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 05:15:24 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 06:01:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

static char		second_arg(t_env *env, const int arg)
{
	if (arg == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	else if (arg == 2)
	{
		if (!get_dir(env, 2))
			return (0);
	}
	else if (arg == 3)
	{
		if (!get_ind(env))
			return (0);
	}
	else
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	return (1);
}

static char		third_arg(t_env *env, const int arg)
{
	if (arg == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	else if (arg == 2)
	{
		if (!get_dir(env, 2))
			return (0);
	}
	else
		return (0);
	return (1);
}

char			get_sti(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "sti");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	if (arg1 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (!second_arg(env, arg2))
		return (0);
	if (!third_arg(env, arg3))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}
