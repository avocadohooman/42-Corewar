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
#include "file.h"
#include <stdio.h> // delete

int			main(int argc, char **argv)
{
	t_file			file;
	int				bytes;
	char 			*line = "sti r1, %:live, %1";
	t_ass 			ass;
	t_instruction 	example;


	example.label = "loop";
	example.statement->opcode = "sti";
	example.statement->arg1 = "r1,";
	example.statement->arg2 = "%:live";
	example.statement->arg3 = "%1";


	if (argc != 2 || !file_extension(argv[1], FILE_EXT))
		print_error(INVALID_FILE);
	file = read_file(argv[1]);
	bytes = write_file(1, &file);
	printf("wrote %d bytes\n", bytes);
	// Here starts bytecode encoding protot
	return (0);
}
