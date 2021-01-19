/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:55:00 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 22:02:11 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "libft.h"
# include <fcntl.h>
# include "error.h"

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

#endif
