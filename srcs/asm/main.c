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

char		*read_champ(char *champ)
{
	char		*line;
	int			fd;
	t_buffer	buffer;
	int			s;

	line = NULL;
	if (((fd = open(champ, O_RDONLY)) == -1))
		print_error(INVALID_FILE);
	s = ft_get_next_line(fd, &line) - 1;
	new_buffer(&buffer, s);
	if (!(insert_buffer(&buffer, line, s - 1)))
		print_error(BUFFER);
	while ((s = ft_get_next_line(fd, &line)) > 0)
	{
		if (!(insert_buffer(&buffer, line, s - 1)))
			print_error(BUFFER);
		ft_strdel(&line);
	}
	printf("%s\n", buffer.data); //delete
	if (ft_get_next_line(fd, &line) < 0)
		print_error(GET_NEXT_LINE);
	return (buffer.data);
}

int			main(int argc, char **argv)
{
	if (argc != 2) // here we also need to check if the file ends in .s
		print_error(USAGE);
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