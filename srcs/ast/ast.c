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

// void	visit_command(t_ast *command)
// {
// 	// printf("command: %s -- %s\n", command->command, command->string);
// }

unsigned char	*visit_header(t_ast *header)
{
	int				i;
	unsigned char	*buf;
	char			*name;
	char			*comment;

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

unsigned char *encode_arg(t_ast *arg, t_label *labels)
{
	unsigned char *encoded_arg;
	unsigned char *buf;
	int i;
	int value;

	if (arg->label)
	{
		if ((value = label_value(labels, arg->label)) < 0)
			exit(1);
		value -= arg->statement_position;
	}
	else
		value = arg->arg_value;
	i = arg->arg_size + 1;
	encoded_arg = ft_memalloc(sizeof(char) * arg->arg_size);
	buf = encoded_arg;
	while (--i > 0)
	{
		*buf = ((unsigned char *)&value)[i - 1];
		buf++;
	}
	return (encoded_arg);
}

unsigned char encode_arg_type(t_ast **args, int nb)
{
	unsigned char code;
	int i;

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
	unsigned char	*encoded_statement;
	unsigned char *buf;
	unsigned char *tmp;

	if (!(encoded_statement = ft_memalloc(sizeof(char) * stmt->statement_size)))
		return (NULL);
	buf = encoded_statement;
	*buf = stmt->statement + 1;
	buf++;
	if (opcode_table[(int)stmt->statement].argument_type)
	{
		*buf = encode_arg_type(stmt->statement_args, stmt->statement_n_args);
		buf++;
	}
	i = -1;
	while (++i < stmt->statement_n_args)
	{
		tmp = encode_arg(stmt->statement_args[i], stmt->label_list);
		ft_memcpy(buf, tmp, stmt->statement_args[i]->arg_size);
		buf += stmt->statement_args[i]->arg_size;
		// free(tmp);	This should be done :)))
	}
    return (encoded_statement);
}

unsigned char       *visit_instruction(t_ast *body)
{
	int i;

	i = -1;

	while (++i < body->compound_size)
    {
		if (body->compound_value[i]->type == AST_STATEMENT)
		{
			return (encode_statement(body->compound_value[i]));
		}
    }
	return ((unsigned char *)ft_strdup(""));
}

unsigned char	*visit_body(t_ast *body)
{
	int	i;
	unsigned char *code;
	unsigned char *tmp;
	unsigned char *encoded_statement;

	i = -1;
	if  (!(code = ft_memalloc(sizeof(unsigned char) * body->body_byte_size)))
		return (NULL);
	tmp = code;
	while (++i < body->compound_size)
    {  
        if (body->compound_value[i]->type == AST_EMPTY)
            continue ;
    	encoded_statement = visit_instruction(body->compound_value[i]);
		ft_memcpy(tmp, encoded_statement, body->compound_value[i]->statement_size);
		tmp += body->compound_value[i]->statement_size;
		free(encoded_statement);
    }
	return (code);
}

char	*visit_label(t_ast *label)
{
    return (label->label);
}

unsigned char	*visit_ast(t_ast *ast)
{
	if (ast->type == AST_COMPOUND)
		return (visit_compound(ast));
	else if (ast->type == AST_HEADER)
		return (visit_header(ast));
	else if (ast->type == AST_BODY)
		return (visit_body(ast));
	else if (ast->type == AST_INSTRUCTION)
		visit_instruction(ast);
    else if (ast->type == AST_LABEL)
		visit_label(ast);
	else if (ast->type == AST_STATEMENT)
		encode_statement(ast);
	// else if (ast->type == AST_ARGUMENT)
	// 	encode_arg(ast);
	// else
	// 	visit_empty(ast);
	return (NULL);
}
