/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:11:12 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/03 12:26:43 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "get_next_line.h"

int			file_extension(char *file, char *expected_extension)
{
	char *extension;

	extension = ft_strrchr(file, '.');
	if (!(ft_strequ(extension, expected_extension)))
		return (0);
	return (1);
}

t_file		read_file(char *filename)
{
	char		*line;
	int			fd;
	t_file		file;
	size_t		s;

	line = NULL;
	if (((fd = open(filename, O_RDONLY)) == -1))
		print_error(INVALID_FILE);
	new_file(&file, 1024);
	while ((s = ft_get_next_line(fd, &line)) > 0)
	{
		line[s - 1] = '\n';
		if (!(insert_file(&file, line, s)))
		{
			close(fd);
			print_error(BUFFER);
		}
		ft_strdel(&line);
	}
	close(fd);
	if (s < 0)
		print_error(GET_NEXT_LINE);
	return (file);
}
