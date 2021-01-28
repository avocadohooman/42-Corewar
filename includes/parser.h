/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:24:30 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 21:29:49 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "libft.h"
# include "lexer.h"
# include "ast.h"

typedef enum	e_parser_error
{
	ERROR_UNKNOWN_COMMAND,
	ERROR_UNEXPECTED_ARG_TYPE,
	ERROR_MALFORMATTED_ARG,
	ERROR_UNKNOWN_STATEMENT
}				t_parser_error;

static const char *g_parser_error[] = {
	[ERROR_UNKNOWN_COMMAND] = "Unknown command.",
	[ERROR_UNEXPECTED_ARG_TYPE] = "Unexpected argument type.",
	[ERROR_MALFORMATTED_ARG] = "Malformatted argument",
	[ERROR_UNKNOWN_STATEMENT] = "Unknown operation."
};

typedef struct	s_parser
{
	t_lexer		*lexer;
	t_token		*prev_token;
	t_token		*current_token;
}				t_parser;

t_parser		*new_parser(t_lexer *lexer);
void			free_parser(t_parser **parser);

void			parser_consume(t_parser *parser, t_type type);

t_ast			*parser_parse(t_parser *parser);
t_ast			*parser_parse_header_instructions(t_parser *parser);
t_ast			*parser_parse_body_instructions(t_parser *parser);
t_ast			*parser_parse_body_arg(t_parser *parser, int opts);

int				is_number(char *string);
int				is_registry(char *string);

void			parser_exit_with_message(t_parser_error type);

#endif
