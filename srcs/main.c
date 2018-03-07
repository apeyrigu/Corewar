/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:55:23 by pcluchet          #+#    #+#             */
/*   Updated: 2018/03/07 22:59:44 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_cycles(t_vm *vm)
{
	if (vm->cycles_since_check >= vm->cycles_to_die)
	{
		reset_period_counter(vm);
		vm->cycles_since_check = 0;
		if (check_lives_process(vm))
		{
			vm->cycles_to_die -= CYCLE_DELTA;
			vm->no_decrease_since = 0;
		}
		else
		{
			vm->no_decrease_since++;
		}
	}
	if (vm->no_decrease_since == MAX_CHECKS)
	{
		vm->no_decrease_since = 0;
		vm->cycles_to_die -= CYCLE_DELTA;
	}
}

void	init_everything(t_vm *vm)
{
	init_arena(vm);
	create_processes(vm);
	init_pc_players(vm);
	write_players(vm);
	init_players(vm);
}

void	do_everything(t_vm *vm)
{
	draw_and_refresh(vm);
	read_pause(vm);
	vm->cycle++;
	play(vm);
	check_debug(vm, 0, 0, 0);
	vm->cycles_since_check++;
	check_cycles(vm);
}

void	free_everything(t_vm *vm)
{
	free_players(vm);
	free_processes(vm);
	free(vm->arena);
	free(vm->arena_map);
}

int		main(int ac, char **av)
{
	t_vm		vm;

	if (ac == 1)
		how_use();
	check_params(ac, av, &vm);
	if (vm.ncurses_mode)
		ncurses_mode(&vm);
	init_everything(&vm);
	while (vm.max_cycles == -1 || vm.cycle < vm.max_cycles)
	{
		do_everything(&vm);
		if (vm.cycles_to_die < 0)
			break ;
		if (end(&vm))
			break ;
	}
	disp_winner(&vm);
	if (vm.max_cycles != -1)
		dump_memory(&vm);
	free_everything(&vm);
	return (0);
}
