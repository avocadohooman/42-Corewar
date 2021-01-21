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
#include <stdio.h>

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

	printf("compound -- size: %d\n", compound->compound_size);
	i = -1;
	while (++i < compound->compound_size)
		visit_ast(compound->compound_value[i]);
	// {
	// 	if (compound->compound_value[i]->type == AST_LABEL)
	// 	{}	// assing label
	// 	else if (compound->compound_value[i]->type == AST_OPERATION)
	// 	{}	// encode statement
	// }
	// encode
	// return buf
}

void	visit_command(t_ast *command)
{
	printf("command: %s -- %s\n", command->command, command->string);
}

void	visit_header(t_ast *header)
{
	int	i;

	printf("header -- size: %d\n", header->compound_size);
	i = -1;
	while (++i < header->compound_size)
		visit_ast(header->compound_value[i]);
}

void	visit_body(t_ast *body)
{
	int	i;

	printf("body -- size: %d\n", body->compound_size);
	i = -1;
	while (++i < body->compound_size)
		visit_ast(body->compound_value[i]);
}

// void	visit_statement(t_ast *statement)
// {
// 	int	i;

// 	printf("statement -- size: %d\n", statement->compound_size);
// 	i = -1;
// 	while (++i < statement->compound_size)
// 		visit_ast(statement->compound_value[i]);
// }

void	visit_label(t_ast *label)
{
	printf("label: %s\n", label->label);
}

void	visit_argument(t_ast *arg)
{
	printf("argument: %d -- %d\n", arg->arg_type, arg->arg_value);
}

void	visit_statement(t_ast *statement)
{
	int	i;

	printf("statement: %d -- number of args %d -- total_size:%d\n",
			statement->statement + 1,
			statement->statement_n_args,
			statement->statement_size);
	i = -1;
	while (++i < statement->statement_n_args)
		visit_argument(statement->statement_args[i]);
}
void	visit_empty(t_ast *empty)
{
	printf("empty\n");
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
		visit_compound(ast);
	else if (ast->type == AST_STATEMENT)
		visit_statement(ast);
	else if (ast->type == AST_LABEL)
		visit_label(ast);
	else if (ast->type == AST_ARGUMENT)
		visit_argument(ast);
	else
		visit_empty(ast);		
}




/*


	l2:		0
	live:	11
_______________

index:	0	l2
		1
		2	live
		3
		4




index:	0	0
		1	6
		2	11
		3	14

6
5
3
3


*/