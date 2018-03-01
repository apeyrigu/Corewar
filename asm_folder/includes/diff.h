/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 04:06:38 by abassibe          #+#    #+#             */
/*   Updated: 2018/02/15 00:47:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFF_H
# define DIFF_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_env
{
	char			str1[1];
	char			str2[1];
	int				fd1;
	int				fd2;
	int				ret1;
	int				ret2;
}					t_env;

#endif
