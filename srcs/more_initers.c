/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_initers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 04:35:05 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 03:49:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_pc_players(t_vm *vm)
{
	t_player	*current_player;
	t_process	*seed_process;
	int			i;

	i = 0;
	current_player = vm->players;
	while (current_player)
	{
		seed_process = get_process_for_player(vm, current_player->num);
		seed_process->pc_index = i * (MEM_SIZE / vm->nbchamps);
		current_player = current_player->next;
		i++;
	}
}

void	init_players(t_vm *vm)
{
	t_player	*current_player;
	t_process	*seed_process;
	int			i;

	i = 0;
	current_player = vm->players;
	while (current_player)
	{
		ft_printf("initing player #%d\n", current_player->num);
		seed_process = get_process_for_player(vm, current_player->num);
		set_cycles_to_go(vm, seed_process);
		current_player = current_player->next;
		i++;
	}
}

void	reset_period_counter(t_vm *vm)
{
	t_player *current_player;

	current_player = vm->players;
	while (current_player)
	{
		current_player->lives_current = 0;
		current_player = current_player->next;
	}
}
