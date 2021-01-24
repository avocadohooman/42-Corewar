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

t_ast	*parser_parse_body_direct(t_parser *parser)
{
	t_ast	*arg;
	int		sign;

	sign = 1;
	parser_consume(parser, TOKEN_DIRECT);
	if (!(arg = init_ast(AST_ARGUMENT)))
		return (NULL);
	arg->arg_type = T_DIR;
	arg->arg_size = 2;
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_COLON);
		arg->label = parser->current_token->value;
		parser_consume(parser, TOKEN_IDENTIFIER);
		return (arg);
	}
	if (parser->current_token->type == TOKEN_NEGATIVE)
	{
		sign = -1;
		parser_consume(parser, TOKEN_NEGATIVE);
	}
	if (!is_number(parser->current_token->value))
		parser_exit_with_message(ERROR_MALFORMATTED_ARG);
	arg->arg_value = ft_atoi(parser->current_token->value) * sign;
	parser_consume(parser, TOKEN_IDENTIFIER);
	return (arg);
}

t_ast	*parser_parse_body_indirect(t_parser *parser)
{
	t_ast	*arg;
	int		sign;

	sign = 1;
	if (!(arg = init_ast(AST_ARGUMENT)))
		return (NULL);
	arg->arg_type = T_IND;
	arg->arg_size = 2;
	if (parser->current_token->type == TOKEN_COLON)
	{
		parser_consume(parser, TOKEN_COLON);
		arg->label = parser->current_token->value;
		parser_consume(parser, TOKEN_IDENTIFIER);
		return (arg);
	}
	if (parser->current_token->type == TOKEN_NEGATIVE)
	{
		sign = -1;
		parser_consume(parser, TOKEN_NEGATIVE);
	}
	if (!is_number(parser->current_token->value))
		parser_exit_with_message(ERROR_MALFORMATTED_ARG);
	arg->arg_value = ft_atoi(parser->current_token->value) * sign;
	parser_consume(parser, TOKEN_IDENTIFIER);
	return (arg);
}

t_ast	*parser_parse_body_registry(t_parser *parser)
{
	t_ast	*arg;
	int		sign;

	if (!(arg = init_ast(AST_ARGUMENT)))
		return (NULL);
	arg->arg_type = T_REG;
	arg->arg_size = 1;
	if (!is_registry(parser->current_token->value))
		parser_exit_with_message(ERROR_MALFORMATTED_ARG);
	if ((arg->arg_value = ft_atoi(parser->current_token->value + 1)) < 1)
		parser_exit_with_message(ERROR_MALFORMATTED_ARG);
	parser_consume(parser, TOKEN_IDENTIFIER);
	return (arg);
}

t_ast	*parser_parse_argtype(int opts, int recieved, 
							t_ast *(*type)(t_parser*), t_parser *parser)
{
	if (!check_argument(opts, recieved))
		parser_exit_with_message(ERROR_UNEXPECTED_ARG_TYPE);
	return (type(parser));
}

t_ast	*parser_parse_body_arg(t_parser *parser, int opts)
{
	if (is_registry(parser->current_token->value))
		return (parser_parse_argtype(opts,
				T_REG, parser_parse_body_registry, parser));
	else if (parser->current_token->type == TOKEN_DIRECT)
		return (parser_parse_argtype(opts,
				T_DIR, parser_parse_body_direct, parser));
	return (parser_parse_argtype(opts,
			T_IND, parser_parse_body_indirect, parser));
}
