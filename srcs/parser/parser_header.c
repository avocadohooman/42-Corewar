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

t_ast	*parser_parse_command_name(t_parser *parser)
{
	t_ast	*command_name;

	if (!(command_name = init_ast(AST_COMMAND)))
		return (NULL);
	command_name->command = parser->current_token->value;
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	command_name->string = parser->current_token->value;
	parser_consume(parser, TOKEN_STRING);
	return (command_name);
}

t_ast	*parser_parse_command_comment(t_parser *parser)
{
	t_ast *command_comment;

	if (!(command_comment = init_ast(AST_COMMAND)))
		return (NULL);
	command_comment->command = parser->current_token->value;
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	command_comment->string = parser->current_token->value;
	parser_consume(parser, TOKEN_STRING);
	return (command_comment);
}

t_ast	*parser_parse_command(t_parser *parser)
{
	char	*value;
	
	value = parser->current_token->value;
	if (ft_strequ(value, NAME_CMD_STRING))
		return (parser_parse_command_name(parser));
	else if (ft_strequ(value, COMMENT_CMD_STRING))
		return (parser_parse_command_comment(parser));
	else
		parser_exit_with_message(ERROR_UNKNOWN_COMMAND);
}

t_ast	*parser_parse_header_statement(t_parser *parser)
{
	t_type	type;

	type = parser->current_token->type;
	if (type == TOKEN_COMMAND)
		return (parser_parse_command(parser));
	return (init_ast(AST_EMPTY));
}

t_ast	*parser_parse_header_statements(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*statement;

	if (!(compound = init_ast(AST_COMPOUND)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *))))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_header_statement(parser)))
		return (NULL);
	compound->compound_size = 1;
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type != TOKEN_COMMAND &&
			parser->current_token->type != TOKEN_NEWLINE)
			break ;
		if ((statement = parser_parse_header_statement(parser)))
		{
			if (!(compound_insert(compound, statement)))
				return (NULL);
		}
	}
	return (compound);
}
