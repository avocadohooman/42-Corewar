/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroorann <seroorane@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:45:48 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 14:24:38 by seroorantane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


int			validate_file_ext(char *file, char *target_ext)
{
	char *file_ext;

	file_ext = ft_strrchr(file, '.');
	if (!(ft_strequ(file_ext, target_ext)))
		return (0);
	return (1);
}

char		*read_champ(char *champ)
{
	char		*line;
	int			fd;
	t_buffer	buffer;
	size_t		s;

	line = NULL;
	if (((fd = open(champ, O_RDONLY)) == -1))
		print_error(INVALID_FILE);
	new_buffer(&buffer, 1024);
	while ((s = ft_get_next_line(fd, &line)) > 0)
	{
		line[s - 1] = '\n';
		if (!(insert_buffer(&buffer, line, s)))
			print_error(BUFFER);
		ft_strdel(&line);
	}
	if (s < 0)
		print_error(GET_NEXT_LINE);
	return (buffer.data);
}

int			main(int argc, char **argv)
{
	if (argc != 2 || !validate_file_ext(argv[1], FILE_EXT))
		print_error(INVALID_FILE);
	read_champ(argv[1]);
	exit(1);
}

/*
**
**
**
**
**
**
**
**
**
**
**
**
*/