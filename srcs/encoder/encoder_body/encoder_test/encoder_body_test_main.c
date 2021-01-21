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
	t_instruction 	*instruction;

	// instruction = (t_instruction *)malloc(sizeof(t_instruction));
	// // loop:
    // //     sti r1,%: live,% 1
	// instruction->label = ft_strdup("loop");
	// instruction->statement = (t_statement *)malloc(sizeof(t_statement));
	// instruction->statement->opcode = ft_strdup("sti");
	// instruction->statement->arguments = (char **)malloc(sizeof(char *) * 3);
	// int i = 0;
	// while (i < 3)
	// {
	// 	instruction->statement->arguments[i] = (char *)malloc(sizeof(char) * 42);
	// 	i++;
	// }

	// instruction->statement->arguments[0] = ft_strdup("r1,");
	// instruction->statement->arguments[1] = ft_strdup("%:live");
	// instruction->statement->arguments[2] = ft_strdup("%1");
	// instruction->statement->arg_type_req = true;
	// instruction->statement->number_arg = 3;
	// instruction->statement->t_dir = 2;

	// // live:
    // //     live %0
	// instruction->next = (t_instruction *)malloc(sizeof(t_instruction));
	// instruction->next->statement =  (t_statement *)malloc(sizeof(t_statement));
	// instruction->next->label = ft_strdup("live");
	// instruction->next->statement->opcode = ft_strdup("live");
	// instruction->next->statement->opcode = "live";
	// instruction->next->statement->arguments = (char **)malloc(sizeof(char *) * 1);
	// instruction->next->statement->arguments[0] = (char *)malloc(sizeof(char) * 42);
	// instruction->next->statement->arguments[0] = "%0";
	// instruction->next->statement->arg_type_req = false;
	// instruction->next->statement->number_arg = 1;
	// instruction->next->statement->t_dir = 4;


    // // ld  %0, r2
	// instruction->next->next = (t_instruction *)malloc(sizeof(t_instruction));
	// instruction->next->next->statement =  (t_statement *)malloc(sizeof(t_statement));
	// instruction->next->next->label = 0;
	// instruction->next->next->statement = (t_statement *)malloc(sizeof(t_statement));
	// instruction->next->next->statement->opcode = ft_strdup("ld");
	// instruction->next->next->statement->arguments = (char **)malloc(sizeof(char *) * 2);
	// instruction->next->next->statement->arguments[0] = ft_strdup("%0,");
	// instruction->next->next->statement->arguments[1] = ft_strdup("r2");
	// instruction->next->next->statement->arg_type_req = true;
	// instruction->next->next->statement->number_arg = 2;
	// instruction->next->next->statement->t_dir = 4;

	// // zjmp%: loop
	// instruction->next->next->next = (t_instruction *)malloc(sizeof(t_instruction));
	// instruction->next->next->next->statement =  (t_statement *)malloc(sizeof(t_statement));
	// instruction->next->next->next->label = 0;
	// instruction->next->next->next->statement->opcode = ft_strdup("zjmp");
	// instruction->next->next->next->statement->arguments = (char **)malloc(sizeof(char *) * 1);
	// instruction->next->next->next->statement->arguments[0] = ft_strdup("%:loop");
	// instruction->next->next->next->statement->arg_type_req = false;
	// instruction->next->next->next->statement->number_arg = 1;
	// instruction->next->next->next->statement->t_dir = 2;

    int i = 0;

	ass.track = 0;
	t_instruction *tmp;

	tmp = instruction;
	ass.buff_slot = 0;
	int fd = open("bytecode", O_RDWR, 0777);
	track_jmps(&ass, instruction);
	while (tmp)
	{
		get_component_size(&ass, tmp->statement, true);
		get_argument_type(&ass, tmp);
		printf("\nInstruction ByteCode: \n");
		get_arguments(&ass, tmp->statement);
		i = 0;
		while (i < ass.buff_slot)
		{
			printf("%.2x ", ass.statement_buff[i]);
			i++;
		}
		printf("\n------\n\n");
		ass.buff_slot = 0;
		tmp = tmp->next;
		write(fd, ass.statement_buff, ass.size);
	}
	close(fd);
	return (0);
}
