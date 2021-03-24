/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:18:20 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 12:30:51 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

static t_ast	*init_ast_2(t_ast *ast)
{
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

t_ast			*init_ast(int type)
{
	t_ast		*ast;

	if (!(ast = ft_memalloc(sizeof(t_ast))))
		return (NULL);
	ast->type = type;
	ast->label = NULL;
	ast->label_list = NULL;
	ast->label_index = 0;
	ast->statement = 0;
	ast->statement_position = 0;
	ast->statement_size = 0;
	ast->statement_n_args = 0;
	ast->statement_args = NULL;
	ast->arg_size = 0;
	ast->arg_type = 0;
	ast->arg_value = 0;
	ast = init_ast_2(ast);
	return (ast);
}
