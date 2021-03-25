/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:54:49 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 15:24:10 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*init_lexer(char *data, size_t size)
{
	t_lexer *lexer;

	if (!data)
		return (NULL);
	if (!(lexer = ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	lexer->data = data;
	lexer->size = size;
	lexer->index = 0;
	lexer->c = data[0];
	lexer->line_number = 1;
	lexer->column = 1;
	return (lexer);
}

void	lex_advance(t_lexer *lexer)
{
	if (lexer->index < lexer->size)
	{
		lexer->index++;
		lexer->c = lexer->data[lexer->index];
		lexer->column++;
	}
}

t_token	*lex_get_next_token(t_lexer *lexer)
{
	while (lexer->c && lexer->index < lexer->size)
	{
		if (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\r')
			lex_skip_whitespace(lexer);
		if (lexer->c == COMMENT_CHAR)
			lex_skip_comment(lexer);
		if (is_label_char(lexer->c))
			return (lex_get_identifier(lexer));
		if (lexer->c == '"')
			return (lex_get_string(lexer));
		if (lexer->c == '.')
			return (lex_get_command(lexer));
		return (lex_get_operator(lexer));
	}
	return (lex_get_operator(lexer));
}

void	free_lexer(t_lexer **lexer)
{
	if (*lexer)
	{
		free(*lexer);
		*lexer = NULL;
	}
}
