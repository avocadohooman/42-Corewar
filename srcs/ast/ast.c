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
	ast->operation = 0;
	ast->operation_size = 0;
	ast->operation_n_args = 0;
	ast->operation_args = NULL;
	ast->arg_size = 0;
	ast->arg_type = 0;
	ast->arg_value = 0;
	ast->command = NULL;
	ast->string = NULL;
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

void    instruction_insert(t_ast *data, t_instruction *instruction)
{
    if (data->label)
}

void	visit_compound(t_ast *compound, t_instruction *instruction)
{
	int	i;

	// printf("compound -- size: %d\n", compound->compound_size);
	i = -1;
	while (++i < compound->compound_size)
		visit_ast(compound->compound_value[i], instruction);
}

void	visit_command(t_ast *command)
{
	// printf("command: %s -- %s\n", command->command, command->string);
}

void	visit_label(t_ast *label)
{
	printf("label: %s\n", label->label);
}

void	visit_argument(t_ast *arg, t_instruction *instruction)
{
    if (arg->label)
        printf("t_dir label: %s\n", arg->label);
	printf("argument: %d -- %d\n", arg->arg_type, arg->arg_value);
}

void	visit_operation(t_ast *operation, t_instruction *instruction)
{
	int	i;

	printf("operation: %d -- number of args %d -- total_size:%d\n",
			operation->operation + 1,
			operation->operation_n_args,
			operation->operation_size);
	i = -1;
	while (++i < operation->operation_n_args)
		visit_argument(operation->operation_args[i], instruction);
}

void	visit_empty(t_ast *empty)
{
	// printf("empty\n");
}

void	visit_ast(t_ast *ast, t_instruction *instruction)
{
	if (ast->type == AST_COMPOUND)
		visit_compound(ast, instruction);
	else if (ast->type == AST_COMMAND)
		visit_command(ast);
	else if (ast->type == AST_LABEL)
		visit_label(ast);
	else if (ast->type == AST_OPERATION)
		visit_operation(ast, instruction);
	else
		visit_empty(ast);		
}
