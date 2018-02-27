/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_use.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:07:49 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/27 18:56:29 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			how_use(void)
{
	ft_printf("######	Output Text mode	######\n");
	ft_printf("	-aff  : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("	-s N -use with-:\n");
	ft_printf("		~1: Show live\n");
	ft_printf("		~2: Show cycles\n");
	ft_printf("		~3: Show operations\n");
	ft_printf("		~4: Show death\n");
	ft_printf("######	Dump Memory		######\n");
	ft_printf("	-d N -Dumps memory after N cycles then exits (min 10)-\n");
	ft_printf("	-w N -Dumps memory after N cycles while end (min 10)-\n");
	ft_printf("######	Ncurses Output Mode	######\n");
	ft_printf("	-v   -Visual Mod-\n");
	exit(0);
}
