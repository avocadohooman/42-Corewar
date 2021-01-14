/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:07:14 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/12 14:39:35 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "op.h"
#include <stdio.h>

void	parser_parse_body_identifier(t_parser *parser)
{
	printf("parse identifier\n");
	parser_consume(parser, TOKEN_IDENTIFIER);
	parser_consume(parser, TOKEN_COLON);
}

void	parser_parse_body_operation(t_parser *parser)
{
	printf("parse operation\n");
	parser_consume(parser, TOKEN_OPERATION);
	// for labels
	if (parser->current_token->type == TOKEN_COLON)
		return ;
	// identify which opcode we have and run its parsing func
}

void	parser_parse_body_statement(t_parser *parser)
{
	if (parser->current_token->type == TOKEN_IDENTIFIER)
		parser_parse_body_identifier(parser);
	if (parser->current_token->type == TOKEN_OPERATION)
		parser_parse_body_operation(parser);
	else
		printf("empty statement\n");
}

void	parser_parse_body_statements(t_parser *parser)
{
	parser_parse_body_statement(parser);
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		parser_parse_body_statement(parser);
	}
}
