/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:35:25 by pcluchet          #+#    #+#             */
/*   Updated: 2016/11/15 20:39:50 by pcluchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *retour;

	retour = (t_list*)malloc(sizeof(t_list));
	if (retour == NULL)
		return (NULL);
	if (content != NULL)
	{
		retour->content = malloc(sizeof(unsigned char) * content_size);
		if (retour->content == NULL)
			return (NULL);
		ft_memcpy(retour->content, content, content_size);
		retour->content_size = content_size;
	}
	else
	{
		retour->content = malloc(1);
		retour->content = NULL;
		retour->content_size = 0;
	}
	retour->next = NULL;
	return (retour);
}
