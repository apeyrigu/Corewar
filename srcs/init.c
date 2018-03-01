/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 06:14:01 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/03/01 19:55:19 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static const	t_pars	g_found[] =
{
	[0] = isachamp,
	[1] = flagvisu,
	[2] = flagnumber,
	[3] = flagcolor,
	[4] = nbcycles,
	[6] = isaff,
	[5] = debug_mod,
	[7] = d_dump,
	[8] = w_dump,
};

unsigned int	ft_endian(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

int				error_args(char *s)
{
	ft_printf("Progam quit cause : %s\n", s);
	exit(0);
	return (0);
}

int				found_key(char c)
{
	int i;

	i = 9 - ft_strlen(ft_strchr("rvncpsfdw", c));
	return (i >= 9 ? error_args("Wrong arg") : i);
}

void			int_t_vm(t_vm *vm)
{
	vm->process = NULL;
	vm->max_cycles = -1;
	vm->players = NULL;
	vm->ncurses_mode = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycle = 1;
	vm->cycles_since_check = 0;
	vm->no_decrease_since = 0;
	vm->debug = 0;
	vm->nbprocess = 0;
	vm->aff = 0;
	vm->ncurses_play = 0;
}

void			check_params(int ac, char **av, t_vm *vm)
{
	int			i;
	t_flag		tmp;

	if (ac == 1)
		how_use();
	i = 0;
	int_t_vm(vm);
	tmp = (t_flag){	.id = 1, .num = 0, .color = 0 };
	while (++i < ac)
		i += g_found[found_key(av[i][ft_strlen(av[i]) - 1])](av, vm, i, &tmp);
	if (tmp.num != 0 || tmp.color != -1)
		error_args("Pas de joueurs ou flag en fin de ligne");
	vm->nbchamps = tmp.id - 1;
}
