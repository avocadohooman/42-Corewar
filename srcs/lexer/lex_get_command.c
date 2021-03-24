/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:25:36 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:54:19 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"

t_token			*lex_get_command(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	if (!(value = ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	value[0] = '.';
	lex_advance(lexer);
	while (ft_isalpha(lexer->c))
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strlcat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	return (init_token(TOKEN_COMMAND, value));
}
