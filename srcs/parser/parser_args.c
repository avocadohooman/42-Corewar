/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:29:26 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/13 23:50:56 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "opcodes.h"
#include <stdio.h>

void	parser_parse_body_direct(t_parser *parser)
{
	parser_consume(parser, TOKEN_DIRECT);
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_COLON);
		parser_consume(parser, TOKEN_IDENTIFIER);
		return ;
	}
	if (!is_number(parser->current_token->value))
		return ; // error
	parser_consume(parser, TOKEN_IDENTIFIER);
}

void	parser_parse_body_indirect(t_parser *parser)
{
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_COLON);
		parser_consume(parser, TOKEN_IDENTIFIER);
		return ;
	}
	if (!is_number(parser->current_token->value))
		return ; // error
	parser_consume(parser, TOKEN_IDENTIFIER);
}

void	parser_parse_body_registry(t_parser *parser)
{
	if (!is_registry(parser->current_token->value))
		return ; // error
	parser_consume(parser, TOKEN_IDENTIFIER);
}

void	parser_parse_argtype(int opts, int recieved, 
							void (*type)(t_parser*), t_parser *parser)
{
	if (!check_argument(opts, recieved))
		return ; // error
	type(parser);
}

void	parser_parse_body_arg(t_parser *parser, int opts)
{
	int			index;
	t_opcode	code;

	if (is_registry(parser->current_token->value))
		parser_parse_argtype(opts, T_REG, parser_parse_body_registry, parser);
	else if (parser->current_token->type == TOKEN_DIRECT)
		parser_parse_argtype(opts, T_DIR, parser_parse_body_direct, parser);
	else
		parser_parse_argtype(opts, T_IND, parser_parse_body_indirect, parser);
}