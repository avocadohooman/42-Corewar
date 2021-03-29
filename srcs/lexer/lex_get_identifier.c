/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:24:10 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/29 08:33:44 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token			*lex_get_identifier(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	if (!(value = ft_memalloc(sizeof(char))))
		return (NULL);
	while (is_label_char(lexer->c))
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strlcat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	if (lexer->c == LABEL_CHAR)
		return (lex_advance_with_token(lexer, init_token(TOKEN_LABEL, value)));
	return (init_token(TOKEN_IDENTIFIER, value));
}
