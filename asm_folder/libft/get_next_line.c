/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:49:33 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 05:31:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

t_buff		*new_buff(int fd, int add, t_buff **buff)
{
	t_buff			*new;

	if (!(new = malloc(sizeof(t_buff))))
		return (NULL);
	new->buff = ft_strnew(BUFF_SIZE);
	new->mem = -1;
	new->fd = fd;
	new->next = NULL;
	if (add)
	{
		new->next = *buff;
		*buff = new;
		return (new);
	}
	return (new);
}

int			read_line(int fd, t_buff *buff, char **line, int verif)
{
	int				r;
	int				i;

	while ((r = read(fd, buff->buff, BUFF_SIZE)) > 0)
	{
		buff->mem = -1;
		(buff->buff)[r] = '\0';
		i = 0;
		while ((buff->buff)[i])
		{
			if ((buff->buff)[i] == '\n')
			{
				*line = ft_strjoinf(*line, ft_strsub(buff->buff, 0, i));
				if ((buff->buff)[i + 1])
					buff->mem = i + 1;
				return (1);
			}
			i++;
		}
		*line = ft_strjoinf(*line, ft_strdup(buff->buff));
		verif = 1;
	}
	if (r == -1)
		return (-1);
	return (verif);
}

int			check_mem(int fd, t_buff *buff, char **line)
{
	int				i;

	i = buff->mem;
	while ((buff->buff)[i])
	{
		if ((buff->buff)[i] == '\n')
		{
			*line = ft_strjoinf(*line, ft_strsub(buff->buff, buff->mem,
						i - buff->mem));
			buff->mem = -1;
			if ((buff->buff)[i + 1])
				buff->mem = i + 1;
			return (1);
		}
		i++;
	}
	*line = ft_strjoinf(*line, ft_strsub(buff->buff, buff->mem, i - buff->mem));
	buff->mem = -1;
	read_line(fd, buff, line, 0);
	return (1);
}

t_buff		*check_buff(int fd, t_buff **copy)
{
	while (*copy)
	{
		if ((*copy)->fd == fd)
			return (*copy);
		else
			*copy = (*copy)->next;
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static t_buff	*buff;
	t_buff			*copy;
	int				exists;

	if (!line)
		return (-1);
	exists = 0;
	if (!buff)
	{
		buff = new_buff(fd, 0, NULL);
		exists = 1;
	}
	copy = buff;
	if (!check_buff(fd, &copy))
		copy = new_buff(fd, 1, &buff);
	*line = ft_strdup("\0");
	if (copy->mem != -1)
		if (check_mem(fd, copy, line))
			return (1);
	return (read_line(fd, copy, line, 0));
}
