/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_body_args_inner.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:27:14 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/15 17:10:25 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "opcodes.h"

int		is_registry(char *string)
{
	if (*string == 'r' && ++string)
		while (ft_isdigit(*string) && string++)
			;
	return (!*string);
}

int		is_number(char *string)
{
	if (*string == '-' && ++string)
		;
	while (ft_isdigit(*string) && string++)
		;
	return (!*string);
}

int		parser_parse_body_arg_sign(t_parser *parser)
{
	if (parser->current_token->type == TOKEN_NEGATIVE)
	{
		parser_consume(parser, TOKEN_NEGATIVE);
		return (-1);
	}
	return (1);
}

t_ast	*parser_parse_body_arg_label(t_parser *parser, t_ast *arg)
{
	parser_consume(parser, TOKEN_COLON);
	arg->label = ft_strdup(parser->current_token->value);
	parser_consume(parser, TOKEN_IDENTIFIER);
	return (arg);
}

t_ast	*parser_parse_body_arg_inner(t_parser *parser, t_ast *arg)
{
	int sign;

	arg->statement_position = parser->bytes;
	if (parser->current_token->type == TOKEN_COLON)
		return (parser_parse_body_arg_label(parser, arg));
	sign = parser_parse_body_arg_sign(parser);
	if (!is_number(parser->current_token->value))
		parser_exit_with_message(parser, ERROR_MALFORMATTED_ARG);
	arg->arg_value = ft_atoi(parser->current_token->value) * sign;
	parser_consume(parser, TOKEN_IDENTIFIER);
	return (arg);
}
