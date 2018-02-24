/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:16:20 by pcluchet          #+#    #+#             */
/*   Updated: 2016/12/04 00:02:39 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

static int			nx(char *str, char tricks)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (tricks)
		return (ft_strlen(str));
	return (-1);
}

static char			*j(char *this, char *that)
{
	char *sub[3];

	sub[0] = this;
	sub[1] = that;
	sub[2] = ft_strjoin(this, that);
	free(this);
	free(that);
	return (sub[2]);
}

static t_fdstuff	*new_fdstuff(int fd)
{
	t_fdstuff *fds;

	fds = (t_fdstuff*)malloc(sizeof(t_fdstuff));
	fds->fd = fd;
	fds->i = 0;
	fds->p = (char*)ft_memalloc(BUFF_SIZE + 1);
	fds->r = BUFF_SIZE;
	return (fds);
}

static t_fdstuff	*fd_in_list(int fd, t_list **liste, char **line)
{
	t_fdstuff	*n;
	t_list		*spoof;

	*line = ft_strdup("");
	spoof = *liste;
	while (spoof != NULL)
	{
		if (((t_fdstuff *)(spoof->content))->fd == fd)
			return ((t_fdstuff *)(spoof->content));
		spoof = spoof->next;
	}
	n = new_fdstuff(fd);
	ft_lstadd(liste, ft_lstnew(n, sizeof(t_fdstuff)));
	free(n);
	n = (t_fdstuff *)((*liste)->content);
	return (n);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*stuffliste;
	t_fdstuff		*n;
	int				k;

	if (!line || fd < 0)
		return (-1);
	n = fd_in_list(fd, &stuffliste, line);
	if ((k = nx(&((n->p)[n->i]), 0)) == -1)
	{
		*line = j(*line, ft_strsub(n->p, n->i, nx(&(n->p[n->i]), 1)));
		while (k == -1 && (n->r = read(fd, n->p, BUFF_SIZE)))
		{
			if ((n->i = 0) || n->r == -1)
				return (-1);
			ft_bzero(&(n->p[n->r]), (BUFF_SIZE - n->r));
			*line = j(*line, ft_strsub(n->p, 0, nx(n->p, 1)));
			k = nx(&(n->p[n->i]), 0);
		}
		n->i += nx((n->p), 1) + 1;
		return ((n->r == 0 && **line == '\0') ? 0 : 1);
	}
	*line = j(*line, ft_strsub((n->p), n->i, nx(&((n->p)[n->i]), 1)));
	n->i += nx(&((n->p)[n->i]), 1) + 1;
	return ((n->r == 0 && **line == '\0') ? 0 : 1);
}
