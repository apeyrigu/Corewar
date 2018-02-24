/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:59:46 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:51:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	decode_lldi(t_vm *vm, t_process *process)
{
	int prs[4];

	if (process->cycles_to_go == 0)
	{
		process->offset = 0;
		if (acquire_params(vm, process, 14, prs))
		{
			do_lldi(vm, prs, process, process->offset);
		}
		process->pc_index += process->offset + 2;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
		process->cycles_to_go--;
}

void	live_for_player(t_vm *vm, int player_num, int order, int proc)
{
	t_player *current_player;

	current_player = vm->players;
	while (current_player)
	{
		if (current_player->num == player_num)
		{
			if (!vm->ncurses_mode)
				ft_printf("player #%d is said to be alive\n", player_num);
			check_debug(vm, proc, vm->debug == 1 ? -1 : 1, &player_num);
			current_player->lives++;
			current_player->lives_current++;
			current_player->last_live_cycle = vm->cycle;
			current_player->last_live_order = order;
			return ;
		}
		check_debug(vm, proc, vm->debug == 1 ? -1 : 1, &player_num);
		current_player = current_player->next;
	}
}

void	decode_live(t_vm *vm, t_process *process)
{
	int read_player;

	if (process->cycles_to_go == 0)
	{
		read_player = read_n_oct(vm, process->pc_index + 1, 4);
		process->lives++;
		live_for_player(vm, read_player, process->order, process->process_id);
		process->pc_index += 5;
		process->cycles_to_go = -1;
		set_cycles_to_go(vm, process);
	}
	else
	{
		process->cycles_to_go--;
	}
}

void	do_ld(t_vm *vm, int *params, t_process *process)
{
	if (params[2] > 0 && params[2] < REG_NUMBER + 1)
	{
		write_reg(process, params[1], params[2]);
		check_debug(vm, process->process_id, 2, params);
	}
	process->carry = !params[1];
}
