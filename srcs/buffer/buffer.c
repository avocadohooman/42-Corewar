/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:27:45 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 21:39:57 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

t_buffer	*new_buffer(t_buffer *b, size_t s)
{
    if (!(b->data = ft_memalloc(s)))
        return (NULL);
    b->size = s;
    b->used = 0;
    return (b);
}

t_buffer	*insert_buffer(t_buffer *b, char *data, size_t data_size)
{
	char	*tmp;
	
	if (b->used + data_size >= b->size)
	{
		b->size *= 2;
		if (!(tmp = realloc(b->data, b->size * sizeof(char))))
			return (NULL);
		b->data = tmp;
		ft_memset(b->data + b->used, 0, b->size - b->used);
	}
	ft_memcpy(b->data + b->used, data, data_size);
	b->used += data_size;
	return (b);
}

void		delete_buffer(t_buffer *b)
{
	free(b->data);
	b->data = NULL;
}
