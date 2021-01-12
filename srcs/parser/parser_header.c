/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:48:49 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/16 13:20:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"
#include "op.h"
#include <stdio.h>

void	parser_parse_command_name(t_parser *parser)
{
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	parser_consume(parser, TOKEN_STRING);
}

void	parser_parse_command_comment(t_parser *parser)
{
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	parser_consume(parser, TOKEN_STRING);
}

void	parser_parse_command(t_parser *parser)
{
	char	*value;
	
	printf("parsing some command\n");
	value = parser->current_token->value;
	if (ft_strequ(value, NAME_CMD_STRING))
		parser_parse_command_name(parser);
	else if (ft_strequ(value, COMMENT_CMD_STRING))
		parser_parse_command_comment(parser);
	else
		printf("Unknown command\n");
}

void	parser_parse_header_statement(t_parser *parser)
{
	t_type	type;

	type = parser->current_token->type;
	if (type == TOKEN_COMMAND)
		parser_parse_command(parser);
	else
		printf("empty statement\n");
}

void	parser_parse_header_statements(t_parser *parser)
{
	parser_parse_header_statement(parser);
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type != TOKEN_COMMAND &&
			parser->current_token->type != TOKEN_NEWLINE)
			break ;
		parser_parse_header_statement(parser);
	}
	printf("header done\n");
}
