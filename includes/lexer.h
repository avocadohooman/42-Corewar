/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:03:11 by npimenof          #+#    #+#             */
/*   Updated: 2021/03/24 13:33:59 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include "token.h"

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

void			lex_skip_whitespace(t_lexer *lexer);
void			lex_skip_comment(t_lexer *lexer);
t_token			*lex_get_identifier(t_lexer *lexer);
t_token			*lex_get_string(t_lexer *lexer);
t_token			*lex_get_command(t_lexer *lexer);
t_token			*lex_get_operator(t_lexer *lexer);
void			free_lexer(t_lexer **lexer);
int				is_operator(char c);
char			*char_to_string(char c);
int				is_label_char(char c);

#endif
