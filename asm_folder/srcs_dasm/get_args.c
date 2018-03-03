/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 01:33:27 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/05 05:52:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

char	get_reg(t_env *env)
{
	int		reg;
	int		value;

	if ((value = read(env->fd_bin, env->str, 1)) > 0)
	{
		reg = env->str[0];
		if (reg < 1 || reg > 16)
		{
			printf("%d\n", reg);
			ERR = ft_strdup("Bad registry size");
			return (0);
		}
	}
	if (!check_value_read(env, value))
		return (0);
	ft_fprintf(env->fd_champ, "r%d", reg);
	return (1);
}

char	get_ind(t_env *env)
{
	int		tab[1];
	int		value;

	if ((value = read(env->fd_bin, env->str, 2)) > 0)
	{
		tab[0] = 0;
		tab[0] |= ((env->str[0] & 0xff) << 8);
		tab[0] |= ((env->str[1] & 0xff));
		ft_fprintf(env->fd_champ, "%d", tab[0]);
	}
	if (!check_value_read(env, value))
		return (0);
	return (1);
}

char	get_dir(t_env *env, int dir_size)
{
	int		tab[1];
	int		value;

	tab[0] = 0;
	if (dir_size == 4 && ((value = read(env->fd_bin, env->str, 4)) > 0))
	{
		tab[0] |= ((env->str[0] & 0xff) << 24);
		tab[0] |= ((env->str[1] & 0xff) << 16);
		tab[0] |= ((env->str[2] & 0xff) << 8);
		tab[0] |= ((env->str[3] & 0xff));
	}
	else if ((value = read(env->fd_bin, env->str, 2)) > 0)
	{
		tab[0] |= ((env->str[0] & 0xff) << 8);
		tab[0] |= ((env->str[1] & 0xff));
	}
	if (!check_value_read(env, value))
		return (0);
	ft_fprintf(env->fd_champ, "%%%d", tab[0]);
	return (1);
}
