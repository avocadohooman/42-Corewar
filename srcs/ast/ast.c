/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:02:40 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/18 14:59:27 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include <stdio.h> // delete
#include "opcodes.h"

t_ast	*init_ast(int type)
{
	t_ast	*ast;

	if (!(ast = ft_memalloc(sizeof(t_ast))))
		return (NULL);
	ast->type = type;
	ast->label = NULL;
	ast->label_index = 0;
	ast->statement = 0;
	ast->statement_size = 0;
	ast->statement_n_args = 0;
	ast->statement_args = NULL;
	ast->arg_size = 0;
	ast->arg_type = 0;
	ast->arg_value = 0;
	ast->command = NULL;
	ast->string = NULL;
	ast->header_value = NULL;
	ast->header_size = 0;
	ast->body_value = NULL;
	ast->body_byte_size = 0;
	ast->instruction_value = NULL;
	ast->instruction_size = 0;
	ast->compound_value = NULL;
	ast->compound_size = 0;
	return (ast);
}

t_ast	*compound_insert(t_ast *compound, t_ast *new)
{
	t_ast	**tmp;

	compound->compound_size += 1;
	if (!(tmp = realloc(compound->compound_value,
					compound->compound_size * sizeof(t_ast *))))
		return (NULL);
	tmp[compound->compound_size - 1] = new;
	compound->compound_value = tmp;
	return (compound);
}

unsigned char	*visit_compound(t_ast *compound)
{
	int				i;
	unsigned char	*header;
	unsigned char	*body;

	i = -1;
	header = NULL;
	body = NULL;
	while (++i < compound->compound_size)
	{
		if (i == 0)
    		header = visit_ast(compound->compound_value[i]);
		else
		{	
			if (!(body = visit_ast(compound->compound_value[i])))
				print_error(5);
		}
	}
	header = realloc(header, (HEADER_SIZE + compound->body_byte_size));
	ft_memmove((header + HEADER_SIZE), body, compound->body_byte_size);
	return (header);
}

void	visit_command(t_ast *command)
{
	// printf("command: %s -- %s\n", command->command, command->string);
}

unsigned char	*visit_header(t_ast *header)
{
	int				i;
	unsigned char	*buf;
	char			*name;
	char			*comment;

	// printf("header -- size: %d\n", header->compound_size);
	i = -1;
	while (++i < header->compound_size)
	{
		if (header->compound_value[i]->command != NULL &&
			!strcmp(header->compound_value[i]->command, ".name"))
			name = header->compound_value[i]->string;
		if (header->compound_value[i]->command != NULL &&
			!strcmp(header->compound_value[i]->command, ".comment"))
			comment = header->compound_value[i]->string;
	}
	buf = encode_output(name, comment, header->body_byte_size);
	return (buf);
}

unsigned char *encode_arg(t_ast *arg) // Either generate buf in func or pass it as param
{
	// Assuming that buf is passed as param!
	// Need to know the size of a arg = 2 || 4 bytes ===>>> struct->arg_size to the rescue!

	// Gather arg data to a string which length is defined in param 'size'
	printf("Encode arg!\n");
	unsigned char *buf;
	int i;

	if (!arg)
	{
		printf("No arg!\n");
		return (NULL);
	}
	if (arg->label)
	{
//		arg->value = FETCH NBR OF BYTES TO JUMP
		printf("encode arg encountered a label.\nConverting label '%s'.\n", arg->label);
	}
	i = arg->arg_size + 1;
	buf = ft_memalloc(sizeof(char) * arg->arg_size); // If !buf, malloc it to existence
	while (--i > 0)
	{
		*buf = ((unsigned char *)&arg->arg_value)[i - 1];
		buf++;
		printf("Got index %d and char: %d\n", i, ((unsigned char *)&arg->arg_value)[i - 1]);
	}
	return (buf);
}

unsigned char encode_arg_type(t_ast **args, int nb)
{
	// Generate arg type code using args and arg->type
	// It's simple

	unsigned char code;
	int i;

	printf("Encode arg type!\n");
	i = -1;
	code = 0;
	while (++i < nb)
		{
			if (args[i]->arg_type == T_REG)		// previously 'r', correct if not t_reg
				code |= 1UL << (6 - (i + i));
			else if (args[i]->arg_type == T_DIR)	// previously '%', correct if not t_dir
				code |= 1UL << (7 - (i + i));
			else
			{
				code |= 1UL << (7 - (i + i));
				code |= 1UL << (6 - (i + i));
			}
		}
	return (code);
};

unsigned char	    *encode_statement(t_ast *stmt)
{
	int	i;
	unsigned char *buf;
	unsigned char *tmp;

	printf("Encode statement!\n");
	if (!(buf = ft_memalloc(sizeof(char) * stmt->statement_size)))
		return (NULL);
	*buf = stmt->statement + 1;
	buf++;
	if (opcode_table[stmt->statement].argument_type)
	{
		*buf = encode_arg_type(stmt->statement_args, stmt->statement_n_args);
		buf++;
	}
	i = -1;
	while (++i < stmt->statement_n_args)
	{
		tmp = encode_arg(stmt->statement_args[i]);
		ft_memcpy(&buf, &tmp, stmt->statement_args[i]->arg_size);
		// free(tmp);	This should be done :)))
	}
	printf("Statement encoded successfully!\n");
    return (buf);
	// printf("statement: %d -- number of args %d -- total_size:%d\n",
	// 		statement->statement + 1,
	// 		statement->statement_n_args,
	// 		statement->statement_size);
	// i = -1;
	// while (++i < statement->statement_n_args)
	// 	visit_argument(statement->statement_args[i], instruction);
}

unsigned char       *visit_instruction(t_ast *body)
{
	int i;

	i = -1;
	printf("Visit instruction!\n");
	printf("Compound size: %d\n", body->compound_size);
	while (++i < body->compound_size)
    {
		if (body->compound_value[i]->type == AST_STATEMENT)
		{
			printf("Going to encode statement!\n");
			return (encode_statement(body->compound_value[i]));
		}
		else
			printf("v_instr: type was: %d\n", body->compound_value[i]->type);
    }
	return ((unsigned char *)ft_strdup(""));
	/*
    int i;
    t_instruction *new_instruction;

    new_instruction = ft_memalloc(sizeof(t_instruction));

    i = -1;
    while (++i < body->compound_size)
    {
        if (body->compound_value[i]->type == AST_LABEL)
            new_instruction->label = visit_label(body->compound_value[i]);
        else if (body->compound_value[i]->type == AST_STATEMENT)
            new_instruction->statement = visit_statement(body->compound_value[i]);
    }
    return new_instruction; */
}

unsigned char	*visit_body(t_ast *body)
{
	int	i;
	unsigned char *code;
	unsigned char *tmp;
    
	// printf("body -- size: %d\n", body->compound_size);
	i = -1;
	code = NULL;
	while (++i < body->compound_size)
    {  
        if (body->compound_value[i]->type == AST_EMPTY)
            continue ;
    	tmp = visit_instruction(body->compound_value[i]);
		// Save code to dynamic buffer here!
    }
    // i = 0;
    // while (tmp)
    // {
    //     printf("----Instruction Start----\n");
    //     if (tmp->label)
    //         printf("LABEL: %s \n", tmp->label);
    //     if (tmp->statement)
    //     {
    //         printf("opcode: %s ", tmp->statement->opcode);
    //         i = 0;
    //         while (i < tmp->statement->number_arg)
    //         {
    //             printf("%s ",tmp->statement->arguments[i]);
    //             i++;
    //         }
    //         printf("\n");
    //         printf("comp size: %d\n", tmp->statement->component_size);
    //         printf("statement code: %#.2x\n", tmp->statement->statement_code);
    //         printf("----Instruction End----\n");
    //     }
    //     tmp = tmp->next;
    // }
    //encoding_hub(instructions->next);
	return (tmp);
}

char	*visit_label(t_ast *label)
{
    // instruction = assign_encoding_data(label, instruction, 1);
    return (label->label);
	// printf("label: %s\n", label->label);
}

void	visit_empty(t_ast *empty)
{
	// printf("empty\n");
}

unsigned char	*visit_ast(t_ast *ast)
{
	if (ast->type == AST_COMPOUND)
		return (visit_compound(ast));
	else if (ast->type == AST_HEADER)
		return (visit_header(ast));
	else if (ast->type == AST_COMMAND)
		visit_command(ast);
	else if (ast->type == AST_BODY)
		return (visit_body(ast));
	else if (ast->type == AST_INSTRUCTION)
		visit_instruction(ast);
    else if (ast->type == AST_LABEL)
		visit_label(ast);
	else if (ast->type == AST_STATEMENT)
		encode_statement(ast);
	else if (ast->type == AST_ARGUMENT)
		encode_arg(ast);
	else
		visit_empty(ast);
	return (NULL);
}
