/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:24:55 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:56:00 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"

t_token			*lex_get_string(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	lex_advance(lexer);
	if (!(value = ft_memalloc(sizeof(char))))
		return (NULL);
	while (lexer->c && lexer->c != '"')
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strncat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	if (!lexer->c)
		return (init_token(TOKEN_EOF, char_to_string(lexer->c)));
	lex_advance(lexer);
	return (init_token(TOKEN_STRING, value));
}
