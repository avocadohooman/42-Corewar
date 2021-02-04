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
#include "label.h"

int         is_registry(char *string) 
{
	if (*string == 'r' && ++string)
		while (ft_isdigit(*string) && string++);
	return (!*string);
    // int len;

    // len = ft_strlen(string);
    // if (string[0] == 'r' && !ft_strchr(string, '-'))
    // {
    //     if (len == 2 && string[1] != '0' && ft_isdigit(string[1]))
    //         return (1);
    //     else if (len == 3 && ft_atoi(&string[1]) != 0 && ft_atoi(&string[2]) != 0)
    //         return (1);
    // }
    // return (0);
}

int         is_number(char *string)
{
	if (*string == '-' && ++string){}
	while (ft_isdigit(*string) && string++);
	return (!*string);
	// int     i;
	// int     zeros;
	// int     len;
	// int     n_digits;

	// i = 0;
	// zeros = 0;
	// len = ft_strlen(string);
	// n_digits = ft_ndigits(ft_atoi(string));
	// while (string[i])
	// {
	// 	if (string[i] == '0')
	// 		zeros++;
	// 	if (string[i + 1] != '0')
	// 		break ;
	// 	i++;
	// }
	// if (string[0] == '-') 
	// {
	// 	len = ft_strlen(&string[1]);
	// 	if ((ft_atoi(string) && (len == zeros + n_digits)) || len == zeros)
	// 		return (1);
	// }
	// else if ((ft_atoi(string) && (len == zeros + n_digits)) || len == zeros)
	// 	return (1);
	// return (0);
}

t_ast	*parser_parse_body_label(t_parser *parser, t_label **labels)
{
	t_ast		*label;
	t_label	*new;

	if (!(label = init_ast(AST_LABEL)))
		return (NULL);
	label->label = parser->prev_token->value;
	new = new_label(label->label);
	new->value = parser->bytes;
	label_push(labels, new);
	parser_consume(parser, TOKEN_COLON);
	return (label);
}

t_ast	*parser_parse_body_identifier(t_parser *parser, t_label **labels)
{
	parser_consume(parser, TOKEN_IDENTIFIER);
	if (parser->current_token->type != TOKEN_COLON &&
		lookup_opcode(parser->prev_token->value) >= 0)
			return (opcode_parse(parser, labels));
	return (parser_parse_body_label(parser, labels));
}

t_ast	*parser_parse_body_instruction(t_parser *parser, t_label **labels)
{
	t_ast	*compound;
	
	if (parser->current_token->type == TOKEN_NEWLINE)
		return (init_ast(AST_EMPTY));
	if (!(compound = init_ast(AST_INSTRUCTION)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *) * 2)))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_body_identifier(parser, labels)))
		return (NULL);
	compound->label_list = *labels;
	compound->statement_size += compound->compound_value[0]->statement_size;
	compound->compound_size += 1;
	if (parser->current_token->type == TOKEN_IDENTIFIER)
	{
		if (!(compound->compound_value[1] = parser_parse_body_identifier(parser, labels)))
			return (NULL);
		compound->statement_size += compound->compound_value[1]->statement_size;
		compound->compound_size += 1;
	}
	return (compound);
}

t_ast	*parser_parse_body_instructions(t_parser *parser)
{
	t_ast	*compound;
	t_ast	*statement;
	t_label *labels;

	labels = NULL;
	if (!(compound = init_ast(AST_BODY)))
		return (NULL);
	if (!(compound->compound_value = ft_memalloc(sizeof(t_ast *))))
		return (NULL);
	if (!(compound->compound_value[0] = parser_parse_body_instruction(parser, &labels)))
		return (NULL);
	compound->body_byte_size += compound->compound_value[0]->statement_size;
	parser->bytes = compound->body_byte_size;
	compound->compound_size += 1;
	while (parser->current_token->type == TOKEN_NEWLINE)
	{
		parser_consume(parser, TOKEN_NEWLINE);
		if (parser->current_token->type == TOKEN_EOF)
			break ;
		if ((statement = parser_parse_body_instruction(parser, &labels)))
		{
			if (!(compound_insert(compound, statement)))
				return (NULL);
			compound->body_byte_size += statement->statement_size;
			parser->bytes = compound->body_byte_size;
		}
	}
	compound->label_list = labels;
	return (compound);
}
