/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:00 by npimenof          #+#    #+#             */
/*   Updated: 2021/02/11 10:37:41 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"
# include <fcntl.h>
# include "error.h"

typedef enum	e_buf_error
{
	ERROR_INVALID_FILE,
	ERROR_ALLOCATION_FAIL
}				t_buf_error;

typedef struct	s_buf
{
	char		*data;
	size_t		size;
	size_t		used;
}				t_buf;


t_buf			*buf_new(t_buf *buf, size_t s);
t_buf			*buf_insert(t_buf *buf, char *data, size_t size);
t_buf			*buf_join(t_buf *buf1, t_buf *buf2);
t_buf			buf_read(char *file);
int				buf_write(t_buf *buf, int fd);
void			buf_free(t_buf **buf);

int				file_extension(char *filename, char *expected_extension);

void			buf_exit_with_message(t_buf_error type);

#endif
