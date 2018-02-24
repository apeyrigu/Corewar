/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:03:56 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 02:44:57 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	end(t_vm *vm)
{
	t_process	*current_process;

	current_process = vm->process;
	if (!current_process)
		return (1);
	return (0);
}

void	disp_winner(t_vm *vm)
{
	t_player	*current_player;
	t_player	*winner_player;
	int			maxcycle;
	int			maxorder;

	maxcycle = 0;
	maxorder = 0;
	current_player = vm->players;
	winner_player = NULL;
	while (current_player)
	{
		if (current_player->last_live_cycle > maxcycle ||
				(current_player->last_live_cycle == maxcycle &&
					current_player->last_live_order >= maxorder))
		{
			winner_player = current_player;
			maxcycle = current_player->last_live_cycle;
			maxorder = current_player->last_live_order;
		}
		current_player = current_player->next;
	}
	if (winner_player)
		ft_printf("Le joueur #%d \"%s\" a gagné\n",
				winner_player->num, winner_player->name);
}

void	free_players(t_vm *vm)
{
	t_player	*current_player;
	t_player	*temp;

	current_player = vm->players;
	while (current_player)
	{
		free(current_player->name);
		free(current_player->comment);
		temp = current_player;
		current_player = current_player->next;
		free(temp);
	}
}

void	free_processes(t_vm *vm)
{
	t_process	*current_process;
	t_process	*temp;

	current_process = vm->process;
	while (current_process)
	{
		temp = current_process;
		current_process = current_process->next;
		free(temp);
	}
}
