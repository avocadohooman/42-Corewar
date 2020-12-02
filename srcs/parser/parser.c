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
		free_token(&(parser->prev_token));
		parser->prev_token = parser->current_token;
		parser->current_token = lex_get_next_token(parser->lexer);
	}
	else
		exit(1);
}

void			free_parser(t_parser **parser)
{
	free_token(&((*parser)->prev_token));
	free_token(&((*parser)->current_token));
	free_lexer(&((*parser)->lexer));
	free(*parser);
	*parser = NULL;
}

void			parser_parse(t_parser *parser, char *data)
{}
