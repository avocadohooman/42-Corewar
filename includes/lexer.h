/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:03:11 by npimenof          #+#    #+#             */
/*   Updated: 2021/04/10 13:14:07 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "token.h"
# include "opcodes.h"
# include "ft_printf.h"

typedef struct	s_lexer
{
	char		*data;
	char		c;
	size_t		size;
	size_t		index;
	size_t		line_number;
	size_t		column;
}				t_lexer;

t_lexer			*init_lexer(char *data, size_t size);
void			free_lexer(t_lexer **lexer);

t_token			*lex_get_next_token(t_lexer *lexer);
void			lex_advance(t_lexer *lexer);
t_token			*lex_advance_with_token(t_lexer *lexer, t_token *token);

void			lex_skip_whitespace(t_lexer *lexer);
void			lex_skip_comment(t_lexer *lexer);
t_token			*lex_get_identifier(t_lexer *lexer);
t_token			*lex_get_string(t_lexer *lexer);
t_token			*lex_get_command(t_lexer *lexer);
t_token			*lex_get_operator(t_lexer *lexer);
void			free_lexer(t_lexer **lexer);

#endif
