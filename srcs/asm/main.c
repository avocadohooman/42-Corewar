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

char	*read_champ(char *file)
{
	char *line;
	int fd;

	fd = open(file);
	line = NULL;
	while (ft_get_next_line(fd, &line) > 0)
	{
		
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_error(USAGE);
	
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