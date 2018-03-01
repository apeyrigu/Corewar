/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 02:38:21 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/15 01:14:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/diff.h"

void	check_diff(t_env *env, int *nl, int *octet)
{
	if (env->str1[0] != env->str2[0])
	{
		ft_printf("\nDifference a l'octet %d :\n\n", *octet);
		ft_printf("{red}[%4d]|[%-4d]\n\n", env->str1[0], env->str2[0]);
		exit(-1);
	}
	ft_printf("{green}[%4d]|[%-4d]", env->str1[0], env->str2[0]);
	(*nl)++;
	if (*nl >= 8)
	{
		ft_printf("\n");
		*nl = 0;
	}
	else
		ft_printf("{blue} ||| ");
	(*octet)++;
}

void	case1(t_env env, int nl)
{
	ft_printf("{red}[%4d]|[NULL]{blue} ||| ", env.str1[0]);
	nl++;
	while ((env.ret1 = read(env.fd1, env.str1, 1)))
	{
		ft_printf("{red}[%4d]|[NULL]", env.str1[0]);
		nl++;
		if (nl >= 8)
		{
			ft_printf("\n");
			nl = 0;
		}
		else
			ft_printf("{blue} ||| ");
	}
}

void	case2(t_env env, int nl)
{
	ft_printf("{red}[NULL]|[%-4d]{blue} ||| ", env.str1[0], env.str2[0]);
	nl++;
	while ((env.ret1 = read(env.fd1, env.str1, 1)))
	{
		ft_printf("{red}[NULL]|[%-4d]", env.str1[0], env.str2[0]);
		nl++;
		if (nl >= 8)
		{
			ft_printf("\n");
			nl = 0;
		}
		else
			ft_printf("{blue} ||| ");
	}
}

void	get_diff(t_env env)
{
	int		octet;
	int		nl;

	octet = 0;
	nl = 0;
	while (1)
	{
		env.ret1 = read(env.fd1, env.str1, 1);
		env.ret2 = read(env.fd2, env.str2, 1);
		if (env.ret1 < 1 || env.ret2 < 1)
			break ;
		check_diff(&env, &nl, &octet);
	}
	if (env.ret1 == 0 && env.ret2 == 0)
	{
		ft_printf("\n");
		exit(1);
	}
	if (env.ret1 > 0)
		case1(env, nl);
	else if (env.ret2 > 0)
		case2(env, nl);
	ft_printf("\n");
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 3)
		return (-1);
	if ((env.fd1 = open(av[1], O_RDONLY)) == -1)
	{
		perror("");
		return (0);
	}
	if ((env.fd2 = open(av[2], O_RDONLY)) == -1)
	{
		perror("");
		return (0);
	}
	get_diff(env);
	return (1);
}
