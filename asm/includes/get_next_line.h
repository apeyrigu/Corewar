/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:50:58 by abassibe          #+#    #+#             */
/*   Updated: 2018/01/20 01:40:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 100

typedef struct		s_buff
{
	char			*buff;
	int				mem;
	int				fd;
	struct s_buff	*next;
	struct s_buff	*prev;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
