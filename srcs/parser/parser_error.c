/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:36:40 by npimenof          #+#    #+#             */
/*   Updated: 2021/04/14 11:47:21 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static const char *g_parser_error[] = {
	[ERROR_UNKNOWN_COMMAND] = "Unknown command.",
	[ERROR_UNEXPECTED_ARG_TYPE] = "Unexpected argument type.",
	[ERROR_MALFORMATTED_ARG] = "Malformatted argument",
	[ERROR_UNKNOWN_STATEMENT] = "Unknown operation."
};

void	parser_exit_with_message(t_parser *parser, t_parser_error type)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr(parser->lexer->line_number);
	ft_putstr_fd(":", 2);
	ft_putnbr(parser->lexer->column);
	ft_putstr_fd("]", 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(g_parser_error[type], 2);
	exit(1);
}

void	parser_exit_consume_error(t_parser *parser, t_type type)
{
	ft_putstr_fd("Error [", 2);
	ft_putnbr(parser->lexer->line_number);
	ft_putstr_fd(":", 2);
	ft_putnbr(parser->lexer->column);
	ft_putstr_fd("]", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("Expected ", 2);
	ft_putstr_fd(g_token_literal[type], 2);
	ft_putstr_fd(", got type ", 2);
	ft_putstr_fd(g_token_literal[parser->current_token->type], 2);
	ft_putstr_fd(" with value ", 2);
	ft_putendl_fd(parser->current_token->value, 2);
	exit(1);
}
