/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:41:24 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 10:47:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include "ast.h"
# include "opcodes.h"

typedef enum	e_parser_error
{
	ERROR_UNKNOWN_COMMAND,
	ERROR_UNEXPECTED_ARG_TYPE,
	ERROR_MALFORMATTED_ARG,
	ERROR_UNKNOWN_STATEMENT
}				t_parser_error;

typedef struct	s_parser
{
	int			bytes;
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
t_ast			*parser_parse_body_statement(
					t_parser *parser, t_label **labels);
t_ast			*parser_parse_body_arg(t_parser *parser, int opts);
t_ast			*parser_parse_body_arg_inner(t_parser *parser, t_ast *arg);

int				is_number(char *string);
int				is_registry(char *string);

void			parser_exit_with_message(t_parser *parser, t_parser_error type);
void			parser_exit_consume_error(t_parser *parser, t_type type);

#endif
