/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:28:06 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:47:49 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"

void			free_lexer(t_lexer **lexer)
{
	if (*lexer)
	{
		free(*lexer);
		*lexer = NULL;
	}
}

int				is_operator(char c)
{
	if (c == LABEL_CHAR || c == DIRECT_CHAR ||
		c == SEPARATOR_CHAR || c == NEWLINE_CHAR)
		return (1);
	return (0);
}

char			*char_to_string(char c)
{
	char		*str;

	if (!(str = ft_strnew(sizeof(char))))
		return (NULL);
	*str = c;
	return (str);
}

void			lex_advance(t_lexer *lexer)
{
	if (lexer->index < lexer->size)
	{
		lexer->index++;
		lexer->c = lexer->data[lexer->index];
		lexer->column++;
	}
}

int				is_label_char(char c)
{
	if (ft_strchr(LABEL_CHARS, c))
		return (1);
	return (0);
}
