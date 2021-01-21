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
#include <stdio.h> // delete

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

void	visit_compound(t_ast *compound, t_instruction *instruction)
{
	int	i;

	// printf("compound -- size: %d\n", compound->compound_size);
	i = -1;
	while (++i < compound->compound_size) 
        visit_ast(compound->compound_value[i], instruction);
	// encode
	// return buf
}

void	visit_command(t_ast *command)
{
	// printf("command: %s -- %s\n", command->command, command->string);
}

void	visit_header(t_ast *header, t_instruction *instruction)
{
	int	i;

	// printf("header -- size: %d\n", header->compound_size);
	i = -1;
	while (++i < header->compound_size)
		visit_ast(header->compound_value[i], instruction);
}

void	visit_body(t_ast *body, t_instruction *instruction)
{
	int	i;
    int amount_of_instructions;

    amount_of_instructions = 0;
    amount_of_instructions = body->body_size;
    instruction = (t_instruction *)malloc(sizeof(t_instruction) * amount_of_instructions);

	// printf("body -- size: %d\n", body->compound_size);
	i = -1;
	while (++i < body->compound_size)
		visit_ast(body->compound_value[i], instruction);
    //
}

void	visit_label(t_ast *label, t_instruction *instruction)
{
    assign_encoding_data(label, instruction, 1);
	// printf("label: %s\n", label->label);
}

void	visit_argument(t_ast *arg, t_instruction *instruction)
{
    // if (arg->label)
    //     printf("t_dir label: %s\n", arg->label);
	// printf("argument: %d -- %d\n", arg->arg_type, arg->arg_value);
}

void	visit_statement(t_ast *statement, t_instruction *instruction)
{
	int	i;
    assign_encoding_data(statement, instruction, 0);
	// printf("statement: %d -- number of args %d -- total_size:%d\n",
	// 		statement->statement + 1,
	// 		statement->statement_n_args,
	// 		statement->statement_size);
	i = -1;
	while (++i < statement->statement_n_args)
		visit_argument(statement->statement_args[i], instruction);
}

void	visit_empty(t_ast *empty)
{
	// printf("empty\n");
}

void	visit_ast(t_ast *ast, t_instruction *instruction)
{
	if (ast->type == AST_COMPOUND)
		visit_compound(ast, instruction);
	else if (ast->type == AST_HEADER)
		visit_header(ast, instruction);
	else if (ast->type == AST_COMMAND)
		visit_command(ast);
	else if (ast->type == AST_BODY)
		visit_body(ast, instruction);
	else if (ast->type == AST_INSTRUCTION)
		visit_compound(ast, instruction);
    else if (ast->type == AST_LABEL)
		visit_label(ast, instruction);
	else if (ast->type == AST_STATEMENT)
		visit_statement(ast, instruction);
	else if (ast->type == AST_ARGUMENT)
		visit_argument(ast, instruction);
	else
		visit_empty(ast);		
}
