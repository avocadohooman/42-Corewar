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

typedef void	(*t_opcode_parse)(t_parser *parser);
typedef void	(*t_command)(t_parser *parser);

t_parser		*new_parser(t_lexer *lexer);
void			free_parser(t_parser **parser);

void			parser_consume(t_parser *parser, t_type type);

void			parser_parse(t_parser *parser, char *data);

void			parser_parse_body_statements(t_parser *parser);
void			parser_parse_header_statements(t_parser *parser);

void			parser_parse_header(t_parser *parser);
void			parser_parse_command(t_parser *parser);

void			parser_parse_instruction(t_parser *parse);
void			parser_parse_statement(t_parser *parser);
void			parser_parse_label(t_parser *parser);
void			parser_parse_opcode(t_parser *parser);
void			parser_parse_body_args(t_parser *parser);
void			parser_parse_body_label(t_parser *parser);

void            parser_parse_lfork(t_parser *parser);
void            parser_parse_sti(t_parser *parser);
void            parser_parse_fork(t_parser *parser);
void            parser_parse_lld(t_parser *parser);
void            parser_parse_ld(t_parser *parser);
void            parser_parse_add(t_parser *parser);
void            parser_parse_zjmp(t_parser *parser);
void            parser_parse_sub(t_parser *parser);
void            parser_parse_sub(t_parser *parser);
void            parser_parse_ldi(t_parser *parser);
void            parser_parse_or(t_parser *parser);
void            parser_parse_st(t_parser *parser);
void            parser_parse_aff(t_parser *parser);
void            parser_parse_live(t_parser *parser);
void            parser_parse_xor(t_parser *parser);
void            parser_parse_lldi(t_parser *parser);
void            parser_parse_and(t_parser *parser);

void			parser_parse_command_name(t_parser *parser);
void			parser_parse_command_comment(t_parser *parser);

int				is_number(char *string);
int				is_registry(char *string);

#endif