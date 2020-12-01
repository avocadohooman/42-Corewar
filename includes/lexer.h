/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:03:11 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 21:23:10 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include "token.h"

typedef struct	s_lexer
{
	char 		*data;
	size_t		size;
	size_t		index;
	size_t		line_number;
}				t_lexer;

t_lexer			*init_lexer(char *data);
void			free_lexer(t_lexer **lexer);

t_token			*lex_get_next_token(t_lexer *lexer);
void			lex_advance(t_lexer *lexer);

#endif

