/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasmc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 04:08:31 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/03 04:23:14 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dasm.h"

char	get_body(t_env *env)
{
	int		i;
	int		op;

	i = 0;
	alloc_op(env);
	while (i < env->champ_size && read(env->fd_bin, env->str, 1) > 0)
	{
		op = env->str[0];
		if (!env->op[op - 1](env))
			return (0);
	}
	return (1);
}

char	start(t_env *env, const char *file_name)
{
	env->str = ft_strnew(2049);
	if ((env->fd_bin = open(file_name, O_RDONLY)) == -1)
	{
		perror("");
		return (0);
	}
	env->champ_s = creat_bin(file_name);
	remove(env->champ_s);
	if ((env->fd_champ = open(env->champ_s, O_WRONLY | O_CREAT, 0777)) == -1)
	{
		perror("");
		return (0);
	}
	if (!get_magic_number(env))
		return (0);
	if (!get_header(env))
		return (0);
	if (!get_body(env))
		return (0);
	ft_strdel(&env->str);
	return (1);
}

void	free_data(t_env *env)
{
	free(env->op);
	ft_strdel(&env->champ_s);
	ft_strdel(&ERR);
	free(env);
}

int		main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 0;
	if (ac < 2)
		ft_error("No argument", 0);
	if (ac > 2)
		ft_printf("\n{cyan}----------- Champions decompilation ----------\n\n");
	while (++i < ac)
	{
		if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
			return (-1);
		if (!start(env, av[i]))
		{
			ft_printf("{red}ERROR: %s : '%s'\n", env->error, av[i]);
			remove(env->champ_s);
		}
		else
			ft_printf("{green}Decompilation OK : '%s'\n", av[i]);
		free_data(env);
	}
	if (ac > 2)
		ft_printf("\n{cyan}------------------------------------------------\n");
	return (1);
}
