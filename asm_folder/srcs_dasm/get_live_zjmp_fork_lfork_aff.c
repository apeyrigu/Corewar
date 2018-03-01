/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_live_zjmp_fork_lfork_aff.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 05:12:25 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 05:56:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

char	get_live(t_env *env)
{
	ft_fprintf(env->fd_champ, "%-8s", "live");
	if (!get_dir(env, 4))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char	get_zjmp(t_env *env)
{
	ft_fprintf(env->fd_champ, "%-8s", "zjmp");
	if (!get_dir(env, 2))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char	get_fork(t_env *env)
{
	ft_fprintf(env->fd_champ, "%-8s", "fork");
	if (!get_dir(env, 2))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char	get_lfork(t_env *env)
{
	ft_fprintf(env->fd_champ, "%-8s", "lfork");
	if (!get_dir(env, 2))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}

char	get_aff(t_env *env)
{
	int		value;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
		ft_fprintf(env->fd_champ, "%-8s", "aff");
	if (!check_value_read(env, value))
		return (0);
	if (!get_reg(env))
		return (0);
	write(env->fd_champ, "\n", 1);
	return (1);
}
