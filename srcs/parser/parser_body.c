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

    i = 0;
    zeros = 0;
    while (string[i]) 
    {
        if (string[i] == '0')
            zeros++;
        i++;
    }
    if (string[0] == '-') 
    {
         if (ft_atoi(string) && (ft_strlen(&string[1]) == zeros + ft_ndigits(ft_atoi(string))))
            return (1);
    }
    else if (ft_atoi(string) && (ft_strlen(string) == zeros + ft_ndigits(ft_atoi(string))))
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

	printf("parse identifier\n");
	value = parser->current_token->value;
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (parser->current_token->type == TOKEN_COLON)
	{
		printf("parser_parse_label\n");
		parser_parse_body_label(parser);
		return ; // parser_parse_label
	}
	else if (lookup_opcode(value) >= 0)
	{
		printf("opcode_parse(...)\n");
		opcode_parse(parser);
		return ; // opcode_parse(parser);
	}
	else if (is_number(value))
	{
		printf("parser_parse_indirect\n");
		return ; // parser_parse_indirect
	}
	else if (is_registry(value))
	{
		printf("parser_parse_registry\n");
		return ; // parser_parse_registry
	}
}

void	parser_parse_body_operation(t_parser *parser)
{
	int		i;
	
	printf("parse operation\n");
	parser_consume(parser, TOKEN_OPERATION);
	// for labels 
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_COLON);
		return ;
	}
	opcode_parse(parser);
}

void	parser_parse_body_statement(t_parser *parser)
{
	if (parser->current_token->type == TOKEN_NEWLINE)
		printf("empty statement\n");
	parser_parse_body_identifier(parser);
	if (parser->current_token->type != TOKEN_NEWLINE)
		parser_parse_body_identifier(parser);
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
