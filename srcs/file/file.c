/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:20:52 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:23:21 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_buf		*buf_new(t_buf *buf, size_t s)
{
	if (!(buf->data = ft_memalloc(s)))
		return (NULL);
	buf->size = s;
	buf->used = 0;
	return (buf);
}

t_buf		*buf_insert(t_buf *buf, char *data, size_t size)
{
	char	*tmp;

	if (!buf || !data)
		return (buf);
	if (buf->used + size >= buf->size)
	{
		while (buf->size < (buf->used + size))
			buf->size = (buf->size + 1) * 2;
		if (!(tmp = realloc(buf->data, buf->size * sizeof(char))))
			return (NULL);
		buf->data = tmp;
		ft_memset(buf->data + buf->used, 0, buf->size - buf->used);
	}
	ft_memcpy(buf->data + buf->used, data, size);
	buf->used += size;
	return (buf);
}

t_buf		*buf_join(t_buf *buf1, t_buf *buf2)
{
	t_buf	*new;

	if (!buf1 || !buf2)
		return (NULL);
	if (!(new = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	if (!(buf_new(new, buf1->used + buf2->used)))
		return (NULL);
	if (!(buf_insert(new, buf1->data, buf1->used)))
		return (NULL);
	if (!(buf_insert(new, buf2->data, buf2->used)))
		return (NULL);
	return (new);
}

void		buf_free(t_buf **buf)
{
	if (*buf)
	{
		free((*buf)->data);
		(*buf)->data = NULL;
		free(*buf);
		*buf = NULL;
	}
}

static const char *g_file_error[] = {
	[ERROR_INVALID_FILE] = "Invalid file.",
	[ERROR_ALLOCATION_FAIL] = "Allocation error.",
};

void		buf_exit_with_message(t_buf_error type)
{
	ft_putendl_fd(g_file_error[type], 2);
	exit(1);
}
