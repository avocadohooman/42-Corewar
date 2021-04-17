/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:21:47 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:22:04 by gmolin           ###   ########.fr       */
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
