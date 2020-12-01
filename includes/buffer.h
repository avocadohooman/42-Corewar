/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:00 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 16:03:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_H
# define BUFFER_H

typedef struct	s_buffer
{
	char		*data;
	size_t		size;
	size_t		used;
}				t_buffer;

t_buffer		*new_buffer(t_buffer *b, size_t s);
t_buffer		*insert_buffer(t_buffer *b, char *data, size_t data_size);
void			delete_buffer(t_buffer *b);


#endif