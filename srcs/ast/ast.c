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
#include "encoder.h"
#include <stdio.h> // delete
#include "opcodes.h"

char	        *visit_label(t_ast *label);
t_statement	    *visit_statement(t_ast *statement);

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
	ast->body_size = 0;
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

void	visit_compound(t_ast *compound)
{
	int	i;

	// printf("compound -- size: %d\n", compound->compound_size);
	i = -1;
	while (++i < compound->compound_size) 
        visit_ast(compound->compound_value[i]);
	// encode
	// return buf
}

void	visit_command(t_ast *command)
{
	// printf("command: %s -- %s\n", command->command, command->string);
}

void	visit_header(t_ast *header)
{
	int	i;

	// printf("header -- size: %d\n", header->compound_size);
	i = -1;
	while (++i < header->compound_size)
		visit_ast(header->compound_value[i]);
}

t_instruction       *visit_instruction(t_ast *body)
{
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
    return new_instruction;
}

void	visit_body(t_ast *body)
{
	int	i;
    t_instruction *instructions;
    t_instruction *tmp;
    
	// printf("body -- size: %d\n", body->compound_size);
	i = -1;
    instructions = ft_memalloc(sizeof(t_instruction));
    tmp = instructions;
	while (++i < body->compound_size)
    {        
        if (body->compound_value[i]->type == AST_EMPTY)
            continue ;
        tmp->next = visit_instruction(body->compound_value[i]);
        tmp = tmp->next;
    }
    tmp = instructions->next;
    i = 0;
    while (tmp)
    {
        printf("----Instruction Start----\n");
        if (tmp->label)
            printf("LABEL: %s \n", tmp->label);
        printf("opcode: %s ", tmp->statement->opcode);
        i = 0;
        while (i < tmp->statement->number_arg)
        {
            printf("%s ",tmp->statement->arguments[i]);
            i++;
        }
        printf("\n");
        printf("comp size: %d\n", tmp->statement->component_size);
        printf("statement code: %#.2x\n", tmp->statement->statement_code);
        printf("----Instruction End----\n");
        tmp = tmp->next;
    }
    encoding_hub(instructions->next);
}

char	*visit_label(t_ast *label)
{
    // instruction = assign_encoding_data(label, instruction, 1);
    return (label->label);
	// printf("label: %s\n", label->label);
}

void	visit_argument(t_ast *arg)
{
    // if (arg->label)
    //     printf("t_dir label: %s\n", arg->label);
	// printf("argument: %d -- %d\n", arg->arg_type, arg->arg_value);
}

t_statement	    *visit_statement(t_ast *statement)
{
    t_statement *new_statement;
	int	i;
    
    // instruction = assign_encoding_data(statement, instruction, 0);
    printf("statement: %s\n", opcode_table[statement->statement].literal);
    new_statement = ft_memalloc(sizeof(t_statement));
    new_statement = (t_statement *)malloc(sizeof(t_statement));
    new_statement->number_arg = statement->statement_n_args;
    new_statement->component_size = statement->statement_size;
    new_statement->opcode = ft_strdup(opcode_table[statement->statement].literal);
    printf("statement: %s\n", new_statement->opcode);
    new_statement->statement_code = opcode_table[statement->statement].statement_code;
    new_statement->arguments = (char **)malloc(sizeof(char *) * new_statement->number_arg + 1);
	i = -1;
	while (++i < statement->statement_n_args)
		new_statement->arguments[i] = assign_arguments(statement->statement_args[i]);
    return (new_statement);
	// printf("statement: %d -- number of args %d -- total_size:%d\n",
	// 		statement->statement + 1,
	// 		statement->statement_n_args,
	// 		statement->statement_size);
	// i = -1;
	// while (++i < statement->statement_n_args)
	// 	visit_argument(statement->statement_args[i], instruction);
}

void	visit_empty(t_ast *empty)
{
	// printf("empty\n");
}

void	visit_ast(t_ast *ast)
{
	if (ast->type == AST_COMPOUND)
		visit_compound(ast);
	else if (ast->type == AST_HEADER)
		visit_header(ast);
	else if (ast->type == AST_COMMAND)
		visit_command(ast);
	else if (ast->type == AST_BODY)
		visit_body(ast);
	else if (ast->type == AST_INSTRUCTION)
		visit_instruction(ast);
    else if (ast->type == AST_LABEL)
		visit_label(ast);
	else if (ast->type == AST_STATEMENT)
		visit_statement(ast);
	else if (ast->type == AST_ARGUMENT)
		visit_argument(ast);
	else
		visit_empty(ast);		
}
