/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:37 by npimenof          #+#    #+#             */
/*   Updated: 2021/04/14 11:47:32 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*new_parser(t_lexer *lexer)
{
	t_parser	*parser;
	t_token		*token;

	if (!(parser = ft_memalloc(sizeof(t_parser))))
		return (NULL);
	if (!(token = lex_get_next_token(lexer)))
		return (NULL);
	parser->lexer = lexer;
	parser->current_token = token;
	parser->prev_token = NULL;
	return (parser);
}

void		parser_consume(t_parser *parser, t_type type)
{
	if (parser->current_token->type == type)
	{
		token_free(&parser->prev_token);
		parser->prev_token = parser->current_token;
		parser->current_token = lex_get_next_token(parser->lexer);
	}
	else
		parser_exit_consume_error(parser, type);
}

void		free_parser(t_parser **parser)
{
	if (*parser)
	{
		token_free(&((*parser)->prev_token));
		token_free(&((*parser)->current_token));
		free(*parser);
		*parser = NULL;
	}
}

t_ast		*parser_parse_instructions(t_parser *parser)
{
	t_ast	*ast;

	if (!(ast = init_ast(AST_COMPOUND)))
		return (NULL);
	if (!(ast->compound_value = ft_memalloc(sizeof(t_ast *) * 2)))
		return (NULL);
	ast->compound_size = 2;
	if (!(ast->compound_value[0] = parser_parse_header_instructions(parser)))
		return (NULL);
	if (!(ast->compound_value[1] = parser_parse_body_instructions(parser)))
		return (NULL);
	ast->compound_value[0]->body_byte_size =
		ast->compound_value[1]->body_byte_size;
	ast->body_byte_size = ast->compound_value[1]->body_byte_size;
	return (ast);
}

t_ast		*parser_parse(t_parser *parser)
{
	return (parser_parse_instructions(parser));
}
