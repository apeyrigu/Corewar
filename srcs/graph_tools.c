/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:53:28 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 03:48:40 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_pc_for_player(t_vm *vm, int pc, int player_num)
{
	t_process *current_process;

	current_process = vm->process;
	while (current_process)
	{
		if (current_process->num_player == player_num &&
			current_process->pc_index == pc)
			return (1);
		current_process = current_process->next;
	}
	return (0);
}

int		is_pc(t_vm *vm, int pc)
{
	t_process *current_process;

	current_process = vm->process;
	while (current_process)
	{
		if (current_process->pc_index == pc)
			return (1);
		current_process = current_process->next;
	}
	return (0);
}

void	decide_mem_color(t_vm *vm, int where)
{
	int whose;

	whose = ((char*)vm->arena_map)[where];
	wattroff(vm->mem, A_STANDOUT);
	if (is_pc(vm, where))
		wattron(vm->mem, A_STANDOUT);
	if (whose)
	{
		wattron(vm->mem, COLOR_PAIR(get_player_by_num(vm, whose)->color));
	}
	else
		wattron(vm->mem, COLOR_PAIR(6));
}

int		draw_mem(WINDOW *mem, t_vm *vm)
{
	int		x;
	int		y;
	int		cnt;
	char	microbuffer[3];

	y = 1;
	cnt = 0;
	werase(mem);
	box(vm->mem, ACS_VLINE, ACS_HLINE);
	while (y < 65)
	{
		x = 1;
		while (x < 65)
		{
			decide_mem_color(vm, cnt);
			char_to_hex((char*)microbuffer, ((char*)vm->arena)[cnt]);
			mvwprintw(mem, y, x * 3, (char*)microbuffer);
			wattroff(vm->mem, A_STANDOUT);
			wattron(vm->mem, COLOR_PAIR(6));
			x++;
			cnt++;
		}
		y++;
	}
	return (0);
}

int		draw_infos(WINDOW *infos, t_vm *vm)
{
	t_player		*current_player;
	int				i;

	mvwprintw(infos, 1, 1, "Infos");
	mvwprintw(infos, 2, 1, "Cycles : %10d", vm->cycle);
	mvwprintw(infos, 4, 1, "Cycles to die: %4d", vm->cycles_to_die);
	mvwprintw(infos, 5, 1, "Cycles since check: %4d", vm->cycles_since_check);
	mvwprintw(infos, 6, 1, "Checks since decrease: %4d", vm->no_decrease_since);
	i = 0;
	current_player = vm->players;
	while (current_player)
	{
		mvwprintw(infos, 9 + (i * 10), 1, "Joueur #%d : %s",
				current_player->num,
				current_player->name);
		mvwprintw(infos, 9 + (i * 10) + 3, 1, "Lives :%d",
				current_player->lives);
		mvwprintw(infos, 9 + (i * 10) + 4, 1, "Lives in period:%d",
				current_player->lives_current);
		mvwprintw(infos, 9 + (i * 10) + 5, 1, "Last live cycle :%d",
				current_player->last_live_cycle);
		current_player = current_player->next;
		i++;
	}
	return (0);
}
