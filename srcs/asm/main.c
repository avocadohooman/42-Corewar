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
	t_instruction 	instruction;


	// loop:
    //     sti r1,%: live,% 1

	instruction.label = ft_strdup("loop");
	instruction.statement = (t_statement *)malloc(sizeof(t_statement));
	instruction.statement->opcode = ft_strdup("sti");
	instruction.statement->arguments = (char **)malloc(sizeof(char *) * 3);
	int i = 0;
	while (i < 3)
	{
		instruction.statement->arguments[i] = (char *)malloc(sizeof(char) * 42);
		i++;
	}

	instruction.statement->arguments[0] = ft_strdup("r1,");
	instruction.statement->arguments[1] = ft_strdup("%:live,");
	instruction.statement->arguments[2] = ft_strdup("%1");
	instruction.statement->arg_type_req = true;
	instruction.statement->number_arg = 3;
	instruction.statement->t_dir = 2;

	// live:
    //     live %0

	instruction.next = (t_instruction *)malloc(sizeof(t_instruction));
	instruction.next->statement =  (t_statement *)malloc(sizeof(t_statement));
	instruction.next->statement->opcode = ft_strdup("live");
	instruction.next->statement->opcode = "live";
	instruction.next->statement->arguments = (char **)malloc(sizeof(char *) * 1);
	instruction.next->statement->arguments[0] = (char *)malloc(sizeof(char) * 42);
	instruction.next->statement->arguments[0] = "%0";
	instruction.next->statement->arg_type_req = false;
	instruction.next->statement->number_arg = 1;
	instruction.next->statement->t_dir = 4;


    // ld% 0, r2

	instruction.next->next = (t_instruction *)malloc(sizeof(t_instruction));
	instruction.next->next->statement =  (t_statement *)malloc(sizeof(t_statement));
	instruction.next->next->label = "";
	instruction.next->next->statement = (t_statement *)malloc(sizeof(t_statement));
	instruction.next->next->statement->opcode = ft_strdup("ld");
	instruction.next->next->statement->arguments = (char **)malloc(sizeof(char *) * 2);
	instruction.next->next->statement->arguments[0] = ft_strdup("%0,");
	instruction.next->next->statement->arguments[1] = ft_strdup("r2");
	instruction.next->next->statement->arg_type_req = true;
	instruction.next->next->statement->number_arg = 2;
	instruction.next->next->statement->t_dir = 4;

	// zjmp%: loop
	instruction.next->next->next = (t_instruction *)malloc(sizeof(t_instruction));
	instruction.next->next->next->statement =  (t_statement *)malloc(sizeof(t_statement));
	instruction.next->next->next->label = "";
	instruction.next->next->next->statement->opcode = ft_strdup("zjmp");
	instruction.next->next->next->statement->arguments = (char **)malloc(sizeof(char *) * 1);
	instruction.next->next->next->statement->arguments[0] = ft_strdup("%:loop");
	instruction.next->next->next->statement->arg_type_req = false;
	instruction.next->next->next->statement->number_arg = 1;
	instruction.next->next->next->statement->t_dir = 2;


	ass.size = get_component_size(&ass, instruction.statement);
	// if (argc != 2 || !file_extension(argv[1], FILE_EXT))
	// 	print_error(INVALID_FILE);
	// file = read_file(argv[1]);
	// bytes = write_file(1, &file);
	// printf("wrote %d bytes\n", bytes);
	// Here starts bytecode encoding protot
	ass.statement_buff = (unsigned char*)malloc(sizeof(unsigned char) * ass.size);
	ass.statement_buff[0] = 0x0b;
	if (instruction.statement->arg_type_req)
		get_argument_type(&ass, &instruction);
	printf("Instruction Buff: %.2x %x\n", ass.statement_buff[0], ass.statement_buff[1]);
	get_arguments(&ass, &instruction);
	return (0);
}
