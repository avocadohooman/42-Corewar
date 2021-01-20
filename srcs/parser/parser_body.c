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
#include "opcodes.h"
#include "error.h"
#include "op.h"
#include <stdio.h>

int         is_registry(char *string) 
{
    int len;

    len = ft_strlen(string);
    if (string[0] == 'r' && !ft_strchr(string, '-'))
    {
        if (len == 2 && string[1] != '0' && ft_isdigit(string[1]))
            return (1);
        else if (len == 3 && ft_atoi(&string[1]) != 0 && ft_atoi(&string[2]) != 0)
            return (1);
    }
    return (0);
}

int         is_number(char *string)
{
	int     i;
	int     zeros;
	int     len;
	int     n_digits;

	i = 0;
	zeros = 0;
	len = ft_strlen(string);
	n_digits = ft_ndigits(ft_atoi(string));
	while (string[i])
	{
		if (string[i] == '0')
			zeros++;
		if (string[i + 1] != '0')
			break ;
		i++;
	}
	if (string[0] == '-') 
	{
		len = ft_strlen(&string[1]);
		if ((ft_atoi(string) && (len == zeros + n_digits)) || len == zeros)
			return (1);
	}
	else if ((ft_atoi(string) && (len == zeros + n_digits)) || len == zeros)
		return (1);
	return (0);
}

t_ast	*parser_parse_body_label(t_parser *parser)
{
	t_ast	*label;

	if (!(label = init_ast(AST_LABEL)))
		return (NULL);
	label->label = parser->current_token->value;
	parser_consume(parser, TOKEN_COLON);
	return (label);
}

t_ast	*parser_parse_body_identifier(t_parser *parser)
{
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (parser->current_token->type != TOKEN_COLON &&
		lookup_opcode(parser->prev_token->value) >= 0)
		return (opcode_parse(parser));
	return (parser_parse_body_label(parser));
}

t_ast	*parser_parse_body_statement(t_parser *parser)
{
	t_ast	*compound;

	if (parser->current_token->type == TOKEN_NEWLINE)
		return (init_ast(AST_EMPTY));
	if (!(compound = init_ast(AST_COMPOUND)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *) * 2)))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_body_identifier(parser)))
		return (NULL);
	compound->compound_size += 1;
	if (parser->current_token->type == TOKEN_IDENTIFIER)
	{
		if (!(compound->compound_value[1] = parser_parse_body_identifier(parser)))
			return (NULL);
		compound->compound_size += 1;
	}
	return (compound);
}

t_ast	*parser_parse_body_statements(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*statement;

	if (!(compound = init_ast(AST_COMPOUND)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *))))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_body_statement(parser)))
		return (NULL);
	compound->compound_size += 1;
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type == TOKEN_EOF)
			break ;
		if ((statement = parser_parse_body_statement(parser)))
		{
			if (!(compound_insert(compound, statement)))
				return (NULL);
		}
	}
	return (compound);
}