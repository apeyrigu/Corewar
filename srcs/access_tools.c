/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 01:03:44 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 00:54:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player		*get_player_by_num(t_vm *vm, int num)
{
	t_player	*current_player;

	current_player = vm->players;
	while (current_player)
	{
		if (current_player->num == num)
			return (current_player);
		current_player = current_player->next;
	}
	return (current_player);
}

unsigned char	get_bytes_n(int n, int value)
{
	value = value << (8 * (n - 1));
	value = value >> 8 * 3;
	return (value);
}

void			write_reg(t_process *process, int value, int reg_number)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		process->regs[reg_number][i] = get_bytes_n(i + 1, value);
		i++;
	}
}

int				read_reg(t_process *process, int reg_number)
{
	int		i;
	int		ret;
	int		temp;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		temp = 0;
		temp = temp | process->regs[reg_number][i];
		temp = temp << (4 - i - 1) * 8;
		ret = ret | temp;
		i++;
	}
	return (ret);
}
