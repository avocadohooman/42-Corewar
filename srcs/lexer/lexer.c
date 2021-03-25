/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:54:49 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:55:31 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"

t_token			*lex_get_next_token(t_lexer *lexer)
{
	while (lexer->c && lexer->index < lexer->size)
	{
		if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\r')
			lex_skip_whitespace(lexer);
		if (lexer->c == COMMENT_CHAR)
			lex_skip_comment(lexer);
		if (ft_isalnum(lexer->c))
			return (lex_get_identifier(lexer));
		if (lexer->c == '"')
			return (lex_get_string(lexer));
		if (lexer->c == '.')
			return (lex_get_command(lexer));
		return (lex_get_operator(lexer));
	}
	return (init_token(TOKEN_EOF, char_to_string(lexer->c)));
}
