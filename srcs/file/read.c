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
	int			fd;
	t_file		file;
	char		buf[512 + 1];
	int			ret;

	ft_bzero(buf, 512 + 1);
	if (((fd = open(filename, O_RDONLY)) == -1))
		file_exit_with_message(ERROR_INVALID_FILE);
	new_file(&file, 1024);
	while ((ret = read(fd, buf, 512)) > 0)
	{
		buf[ret] = 0;
		if (!insert_file(&file, buf, ret))
		{
			close(fd);
			file_exit_with_message(ERROR_ALLOCATION_FAIL);
		}
	}
	close(fd);
	return (file);
}
