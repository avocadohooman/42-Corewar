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

t_ast	*parser_parse_body_label(t_parser *parser, t_label **labels)
{
	t_ast	*label;
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
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (parser->current_token->type != TOKEN_COLON &&
		lookup_opcode(parser->prev_token->value) >= 0)
			return (parser_parse_body_statement(parser, labels));
	return (parser_parse_body_label(parser, labels));
}

t_ast	*parser_parse_body_instruction(t_parser *parser, t_label **labels)
{
	t_ast	*instr;

	if (parser->current_token->type == TOKEN_NEWLINE)
		return (init_ast(AST_EMPTY));
	if (!(instr = init_ast(AST_INSTRUCTION)))
		return (NULL);
	if (!(instr->compound_value = ft_memalloc(sizeof(t_ast *) * 2)))
		return (NULL);
	if (!(instr->compound_value[0] =
			parser_parse_body_identifier(parser, labels)))
		return (NULL);
	instr->statement_size += instr->compound_value[0]->statement_size;
	instr->compound_size += 1;
	if (parser->current_token->type == TOKEN_IDENTIFIER &&
		parser->prev_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_IDENTIFIER);
		if (!(instr->compound_value[1] =
				parser_parse_body_statement(parser, labels)))
			return (NULL);
		instr->statement_size += instr->compound_value[1]->statement_size;
		instr->compound_size += 1;
	}
	instr->label_list = *labels;
	return (instr);
}

t_ast	*parser_parse_body_instructions(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*instruction;
	t_label *labels;

	labels = new_label("");
	if (!(compound = init_ast(AST_BODY)))
		return (NULL);
	while (parser->current_token->type == TOKEN_IDENTIFIER ||
			parser->current_token->type == TOKEN_NEWLINE)
	{
		if (!(instruction = parser_parse_body_instruction(parser, &labels)))
			return (NULL);
		if (!(compound_insert(compound, instruction)))
			return (NULL);
		compound->body_byte_size += instruction->statement_size;
		parser->bytes = compound->body_byte_size;
		parser_consume(parser, TOKEN_NEWLINE);
	}
	parser_consume(parser, TOKEN_EOF);
	compound->label_list = labels;
	return (compound);
}
