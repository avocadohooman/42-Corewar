/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:07:14 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/13 22:23:11 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "opcodes.h"
#include "error.h"
#include "op.h"
#include <stdio.h>
#include "label.h"

int         is_registry(char *string) 
{
	if (*string == 'r' && ++string)
		while (ft_isdigit(*string) && string++);
	return (!*string);
}

int         is_number(char *string)
{
	if (*string == '-' && ++string){}
	while (ft_isdigit(*string) && string++);
	return (!*string);
}

t_ast	*parser_parse_body_label(t_parser *parser, t_label **labels)
{
	t_ast		*label;
	t_label	*new;

	if (!(label = init_ast(AST_LABEL)))
		return (NULL);
	label->label = ft_strdup(parser->prev_token->value);
	new = new_label(label->label);
	new->value = parser->bytes;
	label_push(labels, new);
	parser_consume(parser, TOKEN_COLON);
	return (label);
}

t_ast	*parser_parse_body_identifier(t_parser *parser, t_label **labels)
{
	int hotfix;

	hotfix = 0;
	if (parser->prev_token->type == TOKEN_COLON)
		hotfix = 1;
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (hotfix || (parser->current_token->type != TOKEN_COLON &&
		lookup_opcode(parser->prev_token->value) >= 0))
			return (opcode_parse(parser, labels));
	return (parser_parse_body_label(parser, labels));
}

t_ast	*parser_parse_body_instruction(t_parser *parser, t_label **labels)
{
	t_ast	*compound;
	
	if (parser->current_token->type == TOKEN_NEWLINE)
		return (init_ast(AST_EMPTY));
	if (!(compound = init_ast(AST_INSTRUCTION)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *) * 2)))
		return (NULL);
	if (!(compound->compound_value[0] =
			parser_parse_body_identifier(parser, labels)))
		return (NULL);
	compound->statement_size += compound->compound_value[0]->statement_size;
	compound->compound_size += 1;
	if (parser->current_token->type == TOKEN_IDENTIFIER)
	{
		if (!(compound->compound_value[1] =
				parser_parse_body_identifier(parser, labels)))
			return (NULL);
		compound->statement_size += compound->compound_value[1]->statement_size;
		compound->compound_size += 1;
	}
	compound->label_list = *labels;
	return (compound);
}


// too many lines
t_ast	*parser_parse_body_instructions(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*statement;
	t_label *labels;

	labels = new_label("");
	if (!(compound = init_ast(AST_BODY)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *))))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_body_instruction(parser, &labels)))
		return (NULL);
	compound->body_byte_size += compound->compound_value[0]->statement_size;
	parser->bytes = compound->body_byte_size;
	compound->compound_size += 1;
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type == TOKEN_EOF)
			break ;
		if ((statement = parser_parse_body_instruction(parser, &labels)))
		{
			if (!(compound_insert(compound, statement)))
				return (NULL);
			compound->body_byte_size += statement->statement_size;
			parser->bytes = compound->body_byte_size;
		}
	}
	parser_consume(parser, TOKEN_EOF);
	compound->label_list = labels;
	return (compound);
}
