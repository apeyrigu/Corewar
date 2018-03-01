/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeyrigu <apeyrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 06:01:23 by apeyrigu          #+#    #+#             */
/*   Updated: 2018/03/01 20:17:55 by apeyrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <ncurses.h>
# include <stdlib.h>
# include <stdio.h>
# include "op.h"
# include "libft.h"
# include <limits.h>

# define ARENA ((unsigned char*)vm->arena)
# define PCID process->pc_index

extern t_op				g_op_tab[17];

typedef struct			s_player
{
	int					num;
	char				*name;
	char				*comment;
	char				bytecode[CHAMP_MAX_SIZE];
	int					bytecode_size;
	int					lives;
	int					color;
	int					lives_current;
	int					last_live_cycle;
	int					last_live_order;
	struct s_player		*next;
}						t_player;

typedef struct			s_vm
{
	WINDOW				*mem;
	WINDOW				*infos;
	void				*arena;
	int					*arena_map;
	int					cycle;
	struct s_player		*players;
	int					max_cycles;
	char				ncurses_mode;
	int					cycles_to_die;
	int					cycles_since_check;
	int					no_decrease_since;
	int					nbchamps;
	int					nbprocess;
	struct s_process	*process;
	int					aff;
	int					debug;
	int					fd;
	int					ncurses_play;
}						t_vm;

typedef struct			s_process
{
	int					process_id;
	int					num_player;
	unsigned char		regs[17][REG_SIZE];
	int					pc_index;
	char				carry;
	int					cycles_to_go;
	int					lives;
	struct s_process	*next;
	int					offset;
	char				longread;
	int					lastlive;
	int					order;
	int					opcode;
}						t_process;

typedef struct			s_triple
{
	int					first;
	int					second;
	int					third;
}						t_triple;

typedef struct			s_flag
{
	int					id;
	int					num;
	int					color;
	int					tab[4];
	int					champ;

}						t_flag;

typedef int				(*t_pars)(char **s, t_vm *vm, int i, t_flag *tmp);
typedef void			(*t_debug)(t_vm *vm, int proc, int op, int *args);

extern void				(*g_ops[18])(t_vm*, t_process*);

char					end(t_vm *vm);

void					disp_winner(t_vm *vm);

void					free_players(t_vm *vm);

void					free_processes(t_vm *vm);

void					check_cycles(t_vm *vm);

void					free_graphic(t_vm *vm);

void					read_pause(t_vm *vm);

void					init_everything(t_vm *vm);

void					do_everything(t_vm *vm);

void					free_everything(t_vm *vm);

char					int_to_char(unsigned char value);
void					char_to_hex(char *to, unsigned char value);
int						is_pc_for_player(t_vm *vm, int pc, int player_num);
t_player				*get_player_by_num(t_vm *vm, int num);
void					decide_mem_color(t_vm *vm, int where);
int						draw_mem(WINDOW *mem, t_vm *vm);
int						draw_infos(WINDOW *infos, t_vm *vm);
void					ncurses_mode(t_vm *vm);
void					ncurses_refresh(t_vm *vm);
void					init_arena_map (t_vm *vm);
void					init_arena (t_vm *vm);
void					set_cycles_to_go(t_vm *vm, t_process *process);
void					exec_process(t_vm *vm, t_process *process, int order);
void					exec_process_list(t_vm *vm, t_process *process);
void					play(t_vm *vm);
unsigned char			get_bytes_n(int n, int value);
void					write_reg(t_process *process, int value,
		int reg_number);
int						read_reg(t_process *process, int reg_number);
void					add_process(t_vm *vm, t_process to_add);
void					create_processes(t_vm *vm);
void					single_access(t_vm *vm, int where, unsigned char what,
		int who);
t_process				*get_process_for_player(t_vm *vm, int playernum);
void					write_players(t_vm *vm);
void					draw_and_refresh(t_vm *vm);
int						check_lives_process(t_vm *vm);
void					init_pc_players(t_vm *vm);
void					init_players(t_vm *vm);
void					reset_period_counter(t_vm *vm);

void					decode_live(t_vm *vm, t_process *process);
void					decode_sti(t_vm *vm, t_process *process);
void					decode_and(t_vm *vm, t_process *process);
void					decode_zjmp(t_vm *vm, t_process *process);
void					decode_lfork(t_vm *vm, t_process *process);
void					decode_fork(t_vm *vm, t_process *process);
void					decode_lld(t_vm *vm, t_process *process);
void					decode_ld(t_vm *vm, t_process *process);
void					decode_add(t_vm *vm, t_process *process);
void					decode_sub(t_vm *vm, t_process *process);
void					decode_ldi(t_vm *vm, t_process *process);
void					decode_or(t_vm *vm, t_process *process);
void					decode_st(t_vm *vm, t_process *process);
void					decode_aff(t_vm *vm, t_process *process);
void					decode_xor(t_vm *vm, t_process *process);
void					decode_lldi(t_vm *vm, t_process *process);

int						code_to_t(int code);
int						n_bytes_in_type(int opcode, char type);
void					do_lldi(t_vm *vm, int *params, t_process *process,
		int totaloffset);
void					do_xor(t_vm *vm, int *params, t_process *process);
void					do_aff(t_vm *vm, int *params, t_process *process);
void					do_st(t_vm *vm, int *params, t_process *process);
void					do_ld(t_vm *vm, int *params, t_process *process);
void					do_sti(t_vm *vm, t_process *process, int *params);
void					do_and(t_vm *vm, int *params, t_process *process,
		int totaloffset);
void					do_ldi(t_vm *vm, int *params, t_process *process,
		int totaloffset);
void					do_add(t_vm *vm, int *params, t_process *process);
void					do_sub(t_vm *vm, int *params, t_process *process);
void					do_or(t_vm *vm, int *params, t_process *process,
		int totaloffset);
void					do_lld(t_vm *vm, int *params, t_process *process);
char					acquire_params(t_vm *vm, t_process *process,
		int opcode, int params[]);
unsigned char			get_param_type(int n, unsigned char value);
void					check_params(int ac, char **av, t_vm *vm);
void					copy_regs(t_process *process, t_process *destination);
int						error_args(char *s);
unsigned int			ft_endian(unsigned int val);
int						isachamp(char **s, t_vm *vm, int i, t_flag *tmp);
int						flagvisu(char **s, t_vm *vm, int i, t_flag *tmp);
int						nbcycles(char **s, t_vm *vm, int i, t_flag *tmp);
int						flagnumber(char **s, t_vm *vm, int i, t_flag *tmp);
int						flagcolor(char **s, t_vm *vm, int i, t_flag *tmp);
int						aff(char **s, t_vm *vm, int i, t_flag *tmp);
void					how_use();
int						debug_mod(char **s, t_vm *vm, int i, t_flag *tmp);
void					show_cycle(t_vm *vm, int proc, int op, int *arg);
void					im_alive(t_vm *vm, int proc, int op, int *arg);
void					check_debug(t_vm *vm, int proc, int op, int *arg);
int						d_dump(char **s, t_vm *vm, int i, t_flag *tmp);
int						w_dump(char **s, t_vm *vm, int i, t_flag *tmp);
void					dump_memory(t_vm *vm);
void					death_mod(t_vm *vm, int proc, int op, int *arg);
void					dump_process(t_process *process);
void					copy_regs(t_process *process, t_process *destination);
int						read_n_oct(t_vm *vm, int where, int n);
int						isaff(char **s, t_vm *vm, int i, t_flag *tmp);

#endif
