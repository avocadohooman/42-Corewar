/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:26:37 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/29 08:32:24 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static char		*char_to_string(char c)
{
	char	*str;

	if (!(str = ft_strnew(sizeof(char))))
		return (NULL);
	*str = c;
	return (str);
}

t_token			*lex_get_operator(t_lexer *lexer)
{
	if (!lexer->c)
		return (lex_advance_with_token(lexer,
				init_token(TOKEN_EOF, char_to_string(lexer->c))));
		if (lexer->c == LABEL_CHAR)
		return (lex_advance_with_token(lexer,
			init_token(TOKEN_COLON, char_to_string(lexer->c))));
		if (lexer->c == DIRECT_CHAR)
		return (lex_advance_with_token(lexer,
			init_token(TOKEN_DIRECT, char_to_string(lexer->c))));
		if (lexer->c == SEPARATOR_CHAR)
		return (lex_advance_with_token(lexer,
			init_token(TOKEN_SEPARATOR, char_to_string(lexer->c))));
		if (lexer->c == '-')
		return (lex_advance_with_token(lexer,
			init_token(TOKEN_NEGATIVE, char_to_string(lexer->c))));
		if (lexer->c == '\n')
		return (lex_advance_with_token(lexer,
			init_token(TOKEN_NEWLINE, char_to_string(lexer->c))));
		return (init_token(TOKEN_ILLEGAL, char_to_string(lexer->c)));
}
