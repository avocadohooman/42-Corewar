/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:48:49 by npimenof          #+#    #+#             */
/*   Updated: 2021/04/17 17:26:45 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast	*parser_parse_command_name(t_parser *parser)
{
	t_ast	*command_name;

	if (!(command_name = init_ast(AST_COMMAND)))
		return (NULL);
	command_name->command = ft_strdup(parser->current_token->value);
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	command_name->string = ft_strdup(parser->current_token->value);
	parser_consume(parser, TOKEN_STRING);
	return (command_name);
}

t_ast	*parser_parse_command_comment(t_parser *parser)
{
	t_ast *command_comment;

	if (!(command_comment = init_ast(AST_COMMAND)))
		return (NULL);
	command_comment->command = ft_strdup(parser->current_token->value);
	parser_consume(parser, TOKEN_COMMAND);
	while (parser->current_token->type == TOKEN_NEWLINE)
		parser_consume(parser, TOKEN_NEWLINE);
	command_comment->string = ft_strdup(parser->current_token->value);
	parser_consume(parser, TOKEN_STRING);
	return (command_comment);
}

t_ast	*parser_parse_command(t_parser *parser)
{
	if (ft_strequ(parser->current_token->value, NAME_CMD_STRING))
		return (parser_parse_command_name(parser));
	else if (ft_strequ(parser->current_token->value, COMMENT_CMD_STRING))
		return (parser_parse_command_comment(parser));
	parser_exit_with_message(parser, ERROR_UNKNOWN_COMMAND);
	return (NULL);
}

t_ast	*parser_parse_header_instruction(t_parser *parser)
{
	t_type	type;

	type = parser->current_token->type;
	if (type == TOKEN_NEWLINE)
		return (init_ast(AST_EMPTY));
	if (type != TOKEN_COMMAND)
		return (NULL);
	return (parser_parse_command(parser));
}

t_ast	*parser_parse_header_instructions(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*statement;

	if (!(compound = init_ast(AST_HEADER)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *))))
		return (NULL);
	if (!(compound->compound_value[0] =
		parser_parse_header_instruction(parser)))
		return (NULL);
	compound->compound_size = 1;
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type != TOKEN_COMMAND &&
			parser->current_token->type != TOKEN_NEWLINE)
			break ;
		if (!(statement = parser_parse_header_instruction(parser)))
			return (NULL);
		if (!(compound_insert(compound, statement)))
			return (NULL);
	}
	return (compound);
}
