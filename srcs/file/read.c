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

int			file_extension(char *file, char *expected_extension)
{
	char *extension;

	extension = ft_strrchr(file, '.');
	if (!(ft_strequ(extension, expected_extension)))
		return (0);
	return (1);
}

t_buf		buf_read(char *filename)
{
	int			fd;
	t_buf		file;
	char		buf[512 + 1];
	int			ret;

	ft_bzero(buf, 512 + 1);
	if (((fd = open(filename, O_RDONLY)) == -1))
		buf_exit_with_message(ERROR_INVALID_FILE);
	buf_new(&file, 1024);
	while ((ret = read(fd, buf, 512)) > 0)
	{
		buf[ret] = 0;
		if (!buf_insert(&file, buf, ret))
		{
			close(fd);
			buf_exit_with_message(ERROR_ALLOCATION_FAIL);
		}
	}
	close(fd);
	return (file);
}
