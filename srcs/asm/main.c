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
	char 			*line;
	t_ass 			ass;
	t_instruction 	example;


	example.label = "loop";
	example.statement = (char*)malloc(sizeof(char) * 42);
	example.statement->opcode = "sti";
	example.statement->arguments = (char **)malloc(sizeof(char *) * 3);
	int i = 0;
	while (i < 3)
	{
		example.statement->arguments[i] = (char *)malloc(sizeof(char) * 42);
		i++;
	}
	example.statement->arguments[0] = "r1,";
	example.statement->arguments[1] = "%:live";
	example.statement->arguments[2] = "%1";
	example.statement->arg_type_req = true;
	example.statement->number_arg = 3;
	ass.size = 7;

	// if (argc != 2 || !file_extension(argv[1], FILE_EXT))
	// 	print_error(INVALID_FILE);
	// file = read_file(argv[1]);
	// bytes = write_file(1, &file);
	// printf("wrote %d bytes\n", bytes);
	// Here starts bytecode encoding protot
	ass.statement_buff = (unsigned char*)malloc(sizeof(unsigned char) * ass.size);
	ass.statement_buff[0] = 0x0b;
	if (example.statement->arg_type_req)
		get_argument_type(&ass, &example);
	printf("Arg type: 0x%x\n", ass.argument_type);
	// get_arguments(&ass, &example);
	return (0);
}
