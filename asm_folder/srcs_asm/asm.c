/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:22:44 by abassibe          #+#    #+#             */
/*   Updated: 2018/03/03 04:20:37 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_error(const char *str, const int check)
{
	if (check == 0)
		ft_printf("%s\n", str);
	else
		perror("");
	exit(-1);
}

int		main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 0;
	if (ac < 2)
		ft_error("No argument", 0);
	if (ac > 2)
		ft_printf("\n{cyan}------------ Champions compilation -----------\n\n");
	while (++i < ac)
	{
		if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
			return (0);
		alloc_operators(env);
		if (parseur(env, av[i]))
		{
			ft_printf("{green}Compilation OK : '%s'\n", av[i]);
			kingdom_hearts(env);
		}
		else
			ft_printf("{red}An error occured with '%s'\n", av[i]);
		free_operator(env);
	}
	if (ac > 2)
		ft_printf("\n{cyan}------------------------------------------------\n");
}
