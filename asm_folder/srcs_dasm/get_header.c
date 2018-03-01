/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 05:23:58 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/07 05:15:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

char			get_magic_number(t_env *env)
{
	int		magic;
	int		value;

	value = read(env->fd_bin, env->str, 4);
	if (!check_value_read(env, value))
		return (0);
	magic = 0;
	magic |= ((env->str[0] & 0xff) << 24);
	magic |= ((env->str[1] & 0xff) << 16);
	magic |= ((env->str[2] & 0xff) << 8);
	magic |= ((env->str[3] & 0xff));
	if (magic != 15369203)
	{
		ERR = ft_strdup("Bad magic number");
		return (0);
	}
	return (1);
}

static char		get_champ_size(t_env *env)
{
	int		tmp;

	tmp = 0;
	env->champ_size |= ((env->str[0] & 0xff) << 24);
	env->champ_size |= ((env->str[1] & 0xff) << 16);
	env->champ_size |= ((env->str[2] & 0xff) << 8);
	env->champ_size |= ((env->str[3] & 0xff));
	if (env->champ_size > CHAMP_MAX_SIZE)
	{
		env->error = ft_strdup("Champion too big");
		return (0);
	}
	return (1);
}

char			get_header(t_env *env)
{
	int		value;

	if ((value = read(env->fd_bin, env->str, 128)) > 0)
	{
		ft_fprintf(env->fd_champ, ".name \"%s\"\n", env->str);
		clear_buff(env->str);
		if ((value = read(env->fd_bin, env->str, 4)) > 0)
			if ((value = read(env->fd_bin, env->str, 4)) > 0)
			{
				if (!get_champ_size(env))
					return (0);
				if ((value = read(env->fd_bin, env->str, 2048)) > 0)
				{
					ft_fprintf(env->fd_champ, ".comment \"%s\"\n\n", env->str);
					value = read(env->fd_bin, env->str, 4);
					clear_buff(env->str);
				}
			}
	}
	if (!check_value_read(env, value))
		return (0);
	return (1);
}
