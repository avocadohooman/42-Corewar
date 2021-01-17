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

void	parser_parse_body_label(t_parser *parser)
{
	parser_consume(parser, TOKEN_COLON);
}

void	parser_parse_body_identifier(t_parser *parser)
{
	char	*value;

	value = parser->current_token->value;
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_parse_body_label(parser);
		return ;
	}
	else if (lookup_opcode(value) >= 0)
	{
		opcode_parse(parser);
		return ;
	}
	return ; // error
}

void	parser_parse_body_statement(t_parser *parser)
{

	if (parser->current_token->type == TOKEN_IDENTIFIER)
	{
		parser_parse_body_identifier(parser);
		if (parser->current_token->type == TOKEN_IDENTIFIER)
			parser_parse_body_identifier(parser);
	}
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


