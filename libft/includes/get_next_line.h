/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:52:10 by pcluchet          #+#    #+#             */
/*   Updated: 2016/12/03 22:56:02 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 15

typedef struct	s_fdstuff
{
	int			fd;
	int			i;
	char		*p;
	int			r;
}				t_fdstuff;

int				get_next_line(int const fd, char **line);
#endif
