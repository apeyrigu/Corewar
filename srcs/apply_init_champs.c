/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_init_champs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 23:04:44 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/02/27 17:55:50 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*champ_body(t_vm *vm, t_player *play)
{
	t_player *box;

	box = vm->players;
	if (vm->players == NULL)
	{
		vm->players = ft_memalloc(sizeof(t_player));
		ft_memcpy(vm->players, play, sizeof(t_player));
		return (vm->players->bytecode);
	}
	while (box->next)
		box = box->next;
	box->next = ft_memalloc(sizeof(t_player));
	ft_memcpy(box->next, play, sizeof(t_player));
	return (box->next->bytecode);
}

void		champ_head(t_vm *vm, t_player *play, t_header *head, t_flag *tmp)
{
	t_player *p;

	p = vm->players;
	if ((head->prog_name[PROG_NAME_LENGTH]) != 0)
		error_args("wrong");
	else
		play->name = ft_strdup((char *)head->prog_name);
	if ((head->comment[COMMENT_LENGTH]) != 0)
		error_args("Wrong");
	else
		play->comment = ft_strdup((char *)head->comment);
	play->color = tmp->color == 0 ? tmp->id : tmp->color * -1;
	play->bytecode_size = ft_endian(head->prog_size);
	play->num = tmp->num == 0 ? tmp->id : tmp->num * -1;
	while (p)
	{
		if (p->num == play->num)
			error_args("Same -n num");
		p = p->next;
	}
	play->lives = 0;
	play->lives_current = 0;
	play->next = NULL;
	play->last_live_cycle = 0;
}

int			isachamp(char **s, t_vm *vm, int i, t_flag *tmp)
{
	t_player	player;
	t_header	header;
	int			fd;

	if (ft_strcmp(s[i] + ft_strlen(s[i]) - 4, ".cor") != 0)
		error_args("Wrong Argument is champ");
	ft_bzero(header.prog_name, PROG_NAME_LENGTH + 2);
	ft_bzero(header.comment, COMMENT_LENGTH + 1);
	if ((fd = open(s[i], O_RDONLY)) <= -1)
		error_args("Wrong open");
	if (!read(fd, &header, sizeof(t_header)))
		error_args("Wrong Head");
	ft_endian(header.magic) == COREWAR_EXEC_MAGIC ? (void)i
	: error_args("wrong magic number");
	ft_endian(header.prog_size) > CHAMP_MAX_SIZE ? error_args("wrong size")
	: (void)i;
	champ_head(vm, &player, &header, tmp);
	fd = read(fd, champ_body(vm, &player), ft_endian(header.prog_size));
	if (!fd || fd != (int)ft_endian(header.prog_size))
		error_args("Wrong player or size player");
	tmp->num = 0;
	tmp->color = -1;
	if (tmp->id++ >= 5)
		error_args("No more than 5 champs");
	return (0);
}
