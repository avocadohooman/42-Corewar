/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:17:04 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/03 12:17:04 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

t_file	*new_file(t_file *f, size_t s)
{
    if (!(f->data = ft_memalloc(s)))
        return (NULL);
    f->size = s;
    f->used = 0;
    return (f);
}

t_file	*insert_file(t_file *f, char *data, size_t data_size)
{
	char	*tmp;
	
	if (f->used + data_size >= f->size)
	{
		while (f->size < (f->used + data_size))
			f->size *= 2;
		if (!(tmp = realloc(f->data, f->size * sizeof(char))))
			return (NULL);
		f->data = tmp;
		ft_memset(f->data + f->used, 0, f->size - f->used);
	}
	ft_memcpy(f->data + f->used, data, data_size);
	f->used += data_size;
	return (f);
}

void		free_file(t_file *f)
{
	free(f->data);
	f->data = NULL;
}

void		file_exit_with_message(t_file_error type)
{
	ft_putendl_fd(g_file_error[type], 2);
	exit(1);
}
