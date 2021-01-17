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
void			parser_parse_header_statements(t_parser *parser);
void			parser_parse_body_statements(t_parser *parser);
void			parser_parse_body_arg(t_parser *parser, int opts);
void			parser_parse_body_label(t_parser *parser);

int				is_number(char *string);
int				is_registry(char *string);

#endif