/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 07:48:32 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/24 01:44:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_cycle(t_vm *vm, int proc, int op, int *arg)
{
	(void)proc;
	(void)arg;
	if (op == 0)
		ft_printf("It is now cycle %d\n", vm->cycle);
	if (op == -2)
	{
		ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
	}
}

void	death_mod(t_vm *vm, int proc, int op, int *arg)
{
	if (arg == 0)
		return ;
	if (arg[0] == -42)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				proc, op * -1, vm->cycles_to_die);
}

void	im_alive(t_vm *vm, int proc, int op, int *arg)
{
	t_player	*play;

	(void)proc;
	if (op == -1 && *arg > 0)
	{
		play = vm->players;
		while (play->next && play->num != *arg)
			play = play->next;
		ft_printf("Player %d (%s) is said to be alive\n", *arg, play->name);
	}
}

void	dump_memory(t_vm *vm)
{
	char	microbuffer[3];
	int		i;

	i = 0;
	microbuffer[2] = '\0';
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			ft_printf("\n");
			ft_printf("0x");
			char_to_hex((char*)microbuffer, ((char*)&i)[1]);
			ft_printf("%s", microbuffer);
			char_to_hex((char*)microbuffer, ((char*)&i)[0]);
			ft_printf("%s", microbuffer);
			ft_printf(" : ");
		}
		char_to_hex((char*)microbuffer, ((char*)vm->arena)[i]);
		i++;
		ft_printf("%s ", microbuffer);
	}
	ft_printf("\n");
}
