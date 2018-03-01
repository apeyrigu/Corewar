/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ld_st.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 03:24:08 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 05:56:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

static char		get_ld_next(t_env *env, const int arg1, const int arg2)
{
	if (arg1 == 2)
	{
		if (!get_dir(env, 4))
			return (0);
	}
	else if (arg1 == 3)
	{
		if (!get_ind(env))
			return (0);
	}
	else
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg2 == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_ld(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "ld");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	return (get_ld_next(env, arg1, arg2));
}

static char		get_st_next(t_env *env, const int arg1, const int arg2)
{
	if (arg1 == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	else
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg2 == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	else if (arg2 == 3)
	{
		if (!get_ind(env))
			return (0);
	}
	else
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_st(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "st");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	return (get_st_next(env, arg1, arg2));
}
