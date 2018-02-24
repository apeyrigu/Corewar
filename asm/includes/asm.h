/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:46:44 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/06 03:47:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>

# define FD env->fd_bin
# define POS env->pos

typedef struct			s_label
{
	char				*label_name;
	int					pos;
	struct s_label		*next;
}						t_label;

typedef struct			s_ulabel
{
	char				*label;
	struct s_ulabel		*next;
}						t_ulabel;

typedef struct			s_env
{
	char				*file_name;
	int					fd_bin;
	int					fd;
	int					champ_size;
	char				*bin_name;
	t_label				*label;
	t_ulabel			*ulab;
	char				name;
	char				comment;
	char				*save[3];
	char				*op[16];
	int					garb;
	int					i;
	int					pos;
	int					tab[1];
	void				(*opf[16])();
}						t_env;

char					parseur(t_env *env, const char *file_name);
char					pars_name_comment(t_env *env, const char *str);
char					pars_core(t_env *env, const char *str);
char					label_verif(t_ulabel *ulabel, t_label *label);
char					comment_or_empty(const char *str);
void					kingdom_hearts(t_env *env);
int						switch_int(int octet);
void					print_name_comment(t_env *env, const char *str);
char					*creat_bin(char *str);
void					alloc_operators(t_env *env);
void					alloc_op_functions(t_env *env);
char					save_ulabel(t_env *env, const char *str);
char					get_op1(t_env *env, const char *str);
char					is_dir(t_env *env, const char *str);
char					get_op6(t_env *env, const char *str, char **tab);
char					get_op11(t_env *env, const char *str, char **tab);
char					check_ld(t_env *env, char **tab);
char					check_st(t_env *env, char **tab);
char					check_add(t_env *env, char **tab);
char					check_and(t_env *env, char **tab);
char					check_ldi(t_env *env, char **tab);
char					check_sti(t_env *env, char **tab);
char					is_reg(const char *str);
char					is_ind(t_env *env, const char *str);
char					nl_end_of_file(int fd);
void					print_live(t_env *env, const char *str);
void					print_ld(t_env *env, const char *str);
void					print_st(t_env *env, const char *str);
void					print_add(t_env *env, const char *str);
void					print_sub(t_env *env, const char *str);
void					print_and(t_env *env, const char *str);
void					print_or(t_env *env, const char *str);
void					print_xor(t_env *env, const char *str);
void					print_zjmp(t_env *env, const char *str);
void					print_ldi(t_env *env, const char *str);
void					print_sti(t_env *env, const char *str);
void					print_fork(t_env *env, const char *str);
void					print_lld(t_env *env, const char *str);
void					print_lldi(t_env *env, const char *str);
void					print_lfork(t_env *env, const char *str);
void					print_aff(t_env *env, const char *str);
void					print_dir(t_env *env, const char *str, int i,
		int dir_size);
void					print_ind(t_env *env, const char *str, int i);
void					print_reg(t_env *env, const char *str, int *i);
int						locate_label(t_label *label, const char *str);
char					is_dir_print(const char *str, int *i);
char					is_ind_print(const char *str, int *i);
void					free_tab(char **str, char **tab, int i);
void					free_operator(t_env *env);
void					free_struct(t_env *env);
void					ft_error(const char *str, const int check);

#endif
