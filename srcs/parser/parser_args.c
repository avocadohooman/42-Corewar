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

void	parser_parse_body_args(t_parser *parser)
{
	char	*value;

	value = parser->current_token->value;
	if (parser->current_token->type == TOKEN_COLON)
	{
		printf("arg: indirect label\n");
		return ; // parser_parse_indirect
	}
	else if (parser->current_token->type == TOKEN_DIRECT)
	{
		printf("args: direct\n");
		parser_parse_body_direct(parser);
		return ; // parser_parse_dir
	}
	else
	{
		printf("registry or indirect\n");
		return ; // parser_parse_body_identifier(parser);
	}
}