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

typedef struct	s_parser
{
	t_lexer		*lexer;
	t_token		*prev_token;
	t_token		*current_token;
}				t_parser;

t_parser		*new_parser(t_lexer *lexer);
void			free_parser(t_parser **parser);

void			parser_consume(t_parser *parser, t_type type);



void			parser_parse(t_parser *parser, char *data);

void			parser_parse_header(t_parser *parser);
void			parser_parse_command(t_parser *parser);

void			parser_parse_instruction(t_parser *parse);
void			parser_parse_statement(t_parser *parser);
void			parser_parse_label(t_parser *parser);
void			parser_parse_opcode(t_parser *parser);
void			parser_parse_arguments(t_parser *parser);

#endif