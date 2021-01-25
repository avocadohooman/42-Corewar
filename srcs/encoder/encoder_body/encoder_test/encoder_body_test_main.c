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
#include "opcodes.h"
#include <stdio.h> // delete

#include "ast.h"


int			main(int argc, char **argv)
{
	t_ast			*statement;
	unsigned char	*buf;
	unsigned char*arg_type;

	statement = init_ast(AST_STATEMENT);
	statement->statement = 1;
	statement->statement_size = 5;
	statement->statement_n_args = 1;
	statement->statement_args = ft_memalloc(sizeof(t_ast *));
	statement->statement_args[0] = init_ast(AST_ARGUMENT);
	statement->statement_args[0]->arg_type = 2;
	statement->statement_args[0]->arg_value = 10;
	statement->statement_args[0]->arg_size = 4;

	printf("type: %d\nstatement: %s\nsize: %d\nn_args:%d\n\targ_type: %d\n\targ_val: %d\n",
			statement->type,
			opcode_table[statement->statement - 1].literal,
			statement->statement_size,
			statement->statement_n_args,
			statement->statement_args[0]->arg_type,
			statement->statement_args[0]->arg_value
			);
	int	i = -1;
	buf = ft_memalloc(sizeof(char) * statement->statement_size);
	arg_type = buf;
	*buf = (char)statement->statement;
	buf++;
	while (++i < statement->statement_n_args)
	{
		if (opcode_table[statement->statement - 1].argument_type)
		{
			if (statement->statement_args[i]->arg_type == T_DIR)
				*buf |= 1UL << (7 - (i + i));
			buf++;
		}
		if (opcode_table[statement->statement - 1].dir_size == 4)
		{
			*buf = ((unsigned char *)&statement->statement_args[i]->arg_value)[3];
			buf++;
			*buf = ((unsigned char *)&statement->statement_args[i]->arg_value)[2];
			buf++;
		}
		*buf = ((unsigned char *)&statement->statement_args[i]->arg_value)[1];
		buf++;
		*buf = ((unsigned char *)&statement->statement_args[i]->arg_value)[0];
	}
	i = -1;
	while (++i < statement->statement_size)
		printf("%02x ", arg_type[i]);
	// t_file			file;
	// int				bytes;
	// char 			*line;
	// t_ass 			ass;
	// t_instruction 	*instruction;

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

    // int i = 0;

	// ass.track = 0;
	// t_instruction *tmp;

	// tmp = instruction;
	// ass.buff_slot = 0;
	// int fd = open("bytecode", O_RDWR, 0777);
	// track_jmps(&ass, instruction);
	// while (tmp)
	// {
	// 	get_component_size(&ass, tmp->statement, true);
	// 	get_argument_type(&ass, tmp);
	// 	printf("\nInstruction ByteCode: \n");
	// 	get_arguments(&ass, tmp->statement);
	// 	i = 0;
	// 	while (i < ass.buff_slot)
	// 	{
	// 		printf("%.2x ", ass.statement_buff[i]);
	// 		i++;
	// 	}
	// 	printf("\n------\n\n");
	// 	ass.buff_slot = 0;
	// 	tmp = tmp->next;
	// 	write(fd, ass.statement_buff, ass.size);
	// }
	// close(fd);
	return (0);
}
