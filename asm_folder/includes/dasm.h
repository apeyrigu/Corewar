/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 04:06:38 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/06 03:51:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DASM_H
# define DASM_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>

# define ERR env->error

typedef struct			s_env
{
	char				*str;
	int					fd_bin;
	int					fd_champ;
	char				*label[CHAMP_MAX_SIZE];
	int					champ_size;
	char				*champ_s;
	char				*error;
	char				(**op)();
}						t_env;

char					get_header(t_env *env);
char					get_magic_number(t_env *env);
char					get_live(t_env *env);
char					get_ld(t_env *env);
char					get_st(t_env *env);
char					get_add(t_env *env);
char					get_sub(t_env *env);
char					get_and(t_env *env);
char					get_or(t_env *env);
char					get_xor(t_env *env);
char					get_zjmp(t_env *env);
char					get_ldi(t_env *env);
char					get_sti(t_env *env);
char					get_fork(t_env *env);
char					get_lld(t_env *env);
char					get_lldi(t_env *env);
char					get_lfork(t_env *env);
char					get_aff(t_env *env);
char					get_dir(t_env *env, int dir_size);
char					get_ind(t_env *env);
char					get_reg(t_env *env);
char					*creat_bin(const char *str);
void					clear_buff(char *str);
void					alloc_op(t_env*env);
char					check_value_read(t_env *env, int value);
void					ft_error(const char *str, const int check);
#endif
