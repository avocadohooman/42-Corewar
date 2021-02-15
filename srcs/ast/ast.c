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
#include "file.h"

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

t_buf	*visit_compound(t_ast *compound)
{
	int				i;
	t_buf			*buf;
	t_buf			*data;

	if (!(buf = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = -1;
	while (++i < compound->compound_size)
	{
		if (compound->compound_value[i]->type == AST_HEADER)
		{
			if (!(data = visit_header(compound->compound_value[i])))
				return (NULL);
			if (!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
		else if (compound->compound_value[i]->type == AST_BODY)
		{	
			if (!(data = visit_body(compound->compound_value[i])))
				return (NULL);
			if (!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
	}
	return (buf);
}

t_buf	*visit_header(t_ast *header)
{
	int				i;
	unsigned char	*buf;
	char			*name;
	char			*comment;
	t_buf			*bufio;

	if (!(bufio = ft_memalloc(sizeof(t_buf))))
		return (NULL);
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
	if (!(buf_insert(bufio, buf, HEADER_SIZE)))
		return (NULL);
	free(buf);
	buf = NULL;
	return (bufio);
}

unsigned char *encode_arg(t_ast *arg, t_label *labels)
{
	unsigned char *encoded_arg;
	unsigned char *buf;
	int i;
	int value;

	if (!(encoded_arg = ft_memalloc(sizeof(char) * arg->arg_size)))
		return (NULL);
	if (arg->label)
	{
		if ((value = label_value(labels, arg->label)) < 0)
		{
			printf("label not found: %s\n", arg->label);
			exit(1);
		}
		value -= arg->statement_position;
	}
	else
		value = arg->arg_value;
	i = arg->arg_size + 1;
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
			if (args[i]->arg_type == T_REG)
				code |= 1UL << (6 - (i + i));
			else if (args[i]->arg_type == T_DIR)
				code |= 1UL << (7 - (i + i));
			else
			{
				code |= 1UL << (7 - (i + i));
				code |= 1UL << (6 - (i + i));
			}
		}
	return (code);
}

t_buf	    *encode_statement(t_ast *stmt)
{
	int				i;
	unsigned char	byte;
	unsigned char	*argument;
	t_buf			*buf_statement;

	if (!(buf_statement = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	byte = stmt->statement + 1;
	if (!(buf_insert(buf_statement, &byte, 1)))
		return (NULL);
	if (opcode_table[(int)stmt->statement].argument_type)
	{
		byte = encode_arg_type(stmt->statement_args, stmt->statement_n_args);
		if (!(buf_insert(buf_statement, &byte, 1)))
			return (NULL);
	}
	i = -1;
	while (++i < stmt->statement_n_args)
	{
		if (!(argument = encode_arg(stmt->statement_args[i], stmt->label_list)))
			return (NULL);
		if (!(buf_insert(buf_statement, argument, stmt->statement_args[i]->arg_size)))
			return (NULL);
		ft_strdel((char **)&argument);
	}
    return (buf_statement);
}

t_buf       *visit_instruction(t_ast *instruction)
{
	int i;

	i = -1;
	while (++i < instruction->compound_size)
    {
		if (instruction->compound_value[i]->type == AST_STATEMENT)
			return (encode_statement(instruction->compound_value[i]));
    }
	return ((t_buf *)ft_memalloc(sizeof(t_buf)));
}

t_buf	*visit_body(t_ast *body)
{
	int		i;
	t_buf	*buf_body;
	t_buf	*buf_instruction;

	if (!(buf_body = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = -1;
	while (++i < body->compound_size)
    {  
        if (body->compound_value[i]->type == AST_EMPTY)
            continue ;
		if (!(buf_instruction = visit_instruction(body->compound_value[i])))
			return (NULL);
		if (!(buf_insert(buf_body, buf_instruction->data, buf_instruction->used)))
			return (NULL);
		buf_free(&buf_instruction);
    }
	return (buf_body);
}

t_buf	*visit_ast(t_ast *ast)
{
	if (ast->type == AST_COMPOUND)
		return (visit_compound(ast));
	return (NULL);
}
