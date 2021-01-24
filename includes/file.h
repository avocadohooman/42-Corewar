/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:00 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/21 21:50:10 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"
# include <fcntl.h>
# include "error.h"

typedef enum	e_file_error
{
	ERROR_INVALID_FILE,
	ERROR_ALLOCATION_FAIL
}				t_file_error;

static const char *g_file_error[] = {
	[ERROR_INVALID_FILE] = "Invalid file.",
	[ERROR_ALLOCATION_FAIL] = "Allocation error.",
};

typedef struct	s_file
{
	char		*data;
	size_t		size;
	size_t		used;
}				t_file;

t_file			*new_file(t_file *b, size_t s);
t_file			*insert_file(t_file *b, char *data, size_t data_size);
void			free_file(t_file *b);

t_file			read_file(char *filename);
int				write_file(int fd, t_file *file);
int				file_extension(char *filename, char *expected_extension);

void			file_exit_with_message(t_file_error type);

#endif
