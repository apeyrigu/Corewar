/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_graph_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 01:56:12 by pcluchet          #+#    #+#             */
/*   Updated: 2018/02/24 06:25:08 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ncurses_mode(t_vm *vm)
{
	vm->aff = 0;
	vm->ncurses_play = 0;
	initscr();
	if (has_colors() == FALSE || LINES < 66 || COLS < 246)
	{
		endwin();
		ft_printf("Ncurses mode error : either your terminal does not support");
		ft_printf("colors, or terminal size is too small (must be at leai");
		ft_printf("st 246 columns by 66 lines)\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	vm->mem = subwin(stdscr, 66, 128 + 64 + 4, 0, 0);
	vm->infos = subwin(stdscr, 66, 50, 0, 132 + 64);
	box(vm->mem, ACS_VLINE, ACS_HLINE);
	box(vm->infos, ACS_VLINE, ACS_HLINE);
}

void	ncurses_refresh(t_vm *vm)
{
	wrefresh(vm->mem);
	wrefresh(vm->infos);
}

void	draw_and_refresh(t_vm *vm)
{
	if (vm->ncurses_mode)
	{
		draw_infos(vm->infos, vm);
		draw_mem(vm->mem, vm);
		ncurses_refresh(vm);
	}
}

void	read_pause(t_vm *vm)
{
	char k;

	if (vm->ncurses_play)
		timeout(0);
	else
		timeout(-1);
	k = getch();
	if (k == ' ')
		vm->ncurses_play = !vm->ncurses_play;
}

void	free_graphic(t_vm *vm)
{
	if (vm->ncurses_mode)
	{
		endwin();
		free(vm->mem);
		free(vm->infos);
	}
}
