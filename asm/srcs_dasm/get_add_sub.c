/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_add_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 03:43:18 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 05:59:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

static char		get_add_next(t_env *env,
		const int arg1, const int arg2, const int arg3)
{
	if (arg1 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg2 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg3 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_add(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "add");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	return (get_add_next(env, arg1, arg2, arg3));
}

static char		get_sub_next(t_env *env,
		const int arg1, const int arg2, const int arg3)
{
	if (arg1 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg2 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	ft_fprintf(env->fd_champ, ", ");
	if (arg3 != 1)
		return (0);
	else if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char			get_sub(t_env *env)
{
	int		value;
	int		arg1;
	int		arg2;
	int		arg3;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "sub");
	if (!check_value_read(env, value))
		return (0);
	arg1 = (env->str[0] & 0xff) >> 6;
	arg2 = ((env->str[0] & 0xff) << 2 & 0xff) >> 6;
	arg3 = ((env->str[0] & 0xff) << 4 & 0xff) >> 6;
	return (get_sub_next(env, arg1, arg2, arg3));
}
