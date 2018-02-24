/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_or_xor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 03:54:19 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 06:00:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

static char		first_n_second_arg(t_env *env, const int arg)
{
	if (arg == 1)
	{
		if (!get_reg(env))
			return (0);
	}
	else if (arg == 2)
	{
		if (!get_dir(env, 4))
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

char			get_and(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "and");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	if (!first_n_second_arg(env, arg1))
		return (0);
	if (!first_n_second_arg(env, arg2))
		return (0);
	if (arg3 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_or(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "or");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	if (!first_n_second_arg(env, arg1))
		return (0);
	if (!first_n_second_arg(env, arg2))
		return (0);
	if (arg3 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_xor(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "xor");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	if (!first_n_second_arg(env, arg1))
		return (0);
	if (!first_n_second_arg(env, arg2))
		return (0);
	if (arg3 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}
