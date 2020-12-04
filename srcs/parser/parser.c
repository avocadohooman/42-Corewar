/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:37 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/02 12:25:47 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include <stdio.h>

static t_opcode_parse  g_builtin[16] = {
    [OPCODE_LFORK] = parser_parse_lfork,
    [OPCODE_STI] = parser_parse_sti,
    [OPCODE_FORK] = parser_parse_fork,
    [OPCODE_LLD] = parser_parse_lld,
    [OPCODE_LD] = parser_parse_ld,
    [OPCODE_ADD] = parser_parse_add,
    [OPCODE_ZJMP] = parser_parse_zjmp,
    [OPCODE_SUB] = parser_parse_sub,
    [OPCODE_LDI] = parser_parse_ldi,
    [OPCODE_OR] = parser_parse_or,
    [OPCODE_ST] = parser_parse_st,
    [OPCODE_AFF] = parser_parse_aff,
    [OPCODE_LIVE] = parser_parse_live,
    [OPCODE_XOR] = parser_parse_xor,
    [OPCODE_LLDI] = parser_parse_lldi,
    [OPCODE_AND] = parser_parse_and
};


t_parser		*new_parser(t_lexer *lexer)
{
	t_parser	*parser;
	t_token		*token;

	if (!(parser = ft_memalloc(sizeof(t_parser))))
		return (NULL);
	token = lex_get_next_token(lexer);
	parser->lexer = lexer;
	parser->current_token = token;
	parser->prev_token = token;
	return (parser);
}

void			parser_consume(t_parser *parser, t_type type)
{
	if (parser->current_token->type == type)
	{
		parser->prev_token = parser->current_token;
		parser->current_token = lex_get_next_token(parser->lexer);
	}
	else
	{
		printf("Error: Got type '%d', expected '%d' with value: '%s'\n",
				parser->current_token->type,
				type,
				parser->current_token->value);
		exit(1);
	}
}

void			free_parser(t_parser **parser)
{
	free_token(&((*parser)->prev_token));
	free_token(&((*parser)->current_token));
	free_lexer(&((*parser)->lexer));
	free(*parser);
	*parser = NULL;
}

void			parser_parse_command(t_parser *parser)
{
	t_type	type;

	type = parser->current_token->type;
	if (type == COMMAND_NAME)
	{
		parser_consume(parser, COMMAND_NAME);
		parser_consume(parser, TOKEN_STRING);
		printf(".name: '%s'\n", parser->prev_token->value);
	}
	else if (type == COMMAND_COMMENT)
	{
		parser_consume(parser, COMMAND_COMMENT);
		parser_consume(parser, TOKEN_STRING);
		printf(".comment: '%s'\n", parser->prev_token->value);
	}
}

void			parser_parse_opcode(t_parser *parser)
{
	g_builtin[OPCODE_STI](parser);
}

void			parser_parse_label(t_parser *parser)
{
	parser_consume(parser, TOKEN_IDENTIFIER);
	printf("label: '%s'\n", parser->prev_token->value);
	parser_consume(parser, TOKEN_COLON);
	if (is_opcode(parser->current_token->type))
		parser_parse_opcode(parser);
}

void			parser_parse_statement(t_parser *parser)
{
	t_type type;

	type = parser->current_token->type;
	if (type == COMMAND_NAME || type == COMMAND_COMMENT)
		parser_parse_command(parser);
	else if (type == TOKEN_IDENTIFIER)
		parser_parse_label(parser);
	else if (is_opcode(type))
		parser_parse_opcode(parser);
	else
		printf("empty statement\n");
}

void			parser_parse_header(t_parser *parser)
{
	t_type current_type;

	current_type = parser->current_token->type;
	parser_parse_statement(parser);
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		parser_parse_statement(parser);
	}
}

void			parser_parse_statements(t_parser *parser)
{
	parser_parse_header(parser);
	parser_parse_statement(parser);
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		parser_parse_statement(parser);
	}
}

void			parser_parse(t_parser *parser, char *data)
{
	parser_parse_statements(parser);
}
