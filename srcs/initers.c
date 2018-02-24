/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:48:36 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/24 04:40:02 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_arena_map(t_vm *vm)
{
	int		i;

	vm->arena_map = malloc(sizeof(int) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		((int *)(vm->arena_map))[i] = 0x00000000;
		i++;
	}
}

void	init_arena(t_vm *vm)
{
	int		i;

	vm->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		((char *)(vm->arena))[i] = 0x00;
		i++;
	}
	init_arena_map(vm);
}

void	set_cycles_to_go(t_vm *vm, t_process *process)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		process->pc_index = process->pc_index % MEM_SIZE;
		if (process->pc_index < 0)
			process->pc_index = MEM_SIZE + PCID;
		process->opcode = ARENA[PCID];
		if (g_op_tab[i].opcode == ((unsigned char*)vm->arena)[PCID])
			process->cycles_to_go += g_op_tab[i].cycles;
		i++;
	}
}

void	create_processes(t_vm *vm)
{
	t_player	*p1;
	t_process	seed_process;
	int			i;

	p1 = vm->players;
	i = 2;
	while (p1)
	{
		ft_bzero(&seed_process, sizeof(t_process));
		seed_process.num_player = p1->num;
		seed_process.process_id = i - 1;
		seed_process.cycles_to_go = -1;
		seed_process.lastlive = -1;
		write_reg(&seed_process, p1->num, 1);
		add_process(vm, seed_process);
		p1->color = i++;
		p1->last_live_cycle = 0;
		p1->last_live_order = -1;
		p1 = p1->next;
	}
}

void	write_players(t_vm *vm)
{
	t_player	*current_player;
	t_process	*seed_process;
	int			i;

	current_player = vm->players;
	while (current_player)
	{
		seed_process = get_process_for_player(vm, current_player->num);
		i = 0;
		while (i < current_player->bytecode_size)
		{
			single_access(vm, (i + seed_process->pc_index % MEM_SIZE),
					current_player->bytecode[i], current_player->num);
			i++;
		}
		current_player = current_player->next;
	}
}
