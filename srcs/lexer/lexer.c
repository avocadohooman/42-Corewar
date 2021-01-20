/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:03:37 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/02 15:11:20 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "opcodes.h"
#include "op.h"
#include <stdio.h>

t_lexer			*init_lexer(char *data, size_t size)
{
	t_lexer *lexer;

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

void			lex_advance(t_lexer *lexer)
{
	if (lexer->index < lexer->size)
	{
		lexer->index++;
		lexer->c = lexer->data[lexer->index];
		lexer->column++;
	}
}

void			lex_retreat(t_lexer *lexer)
{
	if (lexer->index > 0)
	{
		lexer->index--;
		lexer->c = lexer->data[lexer->index];
		lexer->column--;
	}
}

int				lex_lookahead(t_lexer *lexer, char c)
{
	char	next;

	lex_advance(lexer);
	next = lexer->c;
	lex_retreat(lexer);
	if (c == next)
		return (1);
	return (0);
}

int				is_label_char(char c)
{
	if (ft_strchr(LABEL_CHARS, c))
		return (1);
	return (0);
}

void			lex_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lex_advance(lexer);
}

void			lex_skip_comment(t_lexer *lexer)
{
	while (lexer->c != 13)
		lex_advance(lexer);
}

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

// t_token			*lex_get_keyword(char *value, size_t size)
// {
// 	int		i;

// 	i = 0;
// 	if (lookup_opcode(value) >= 0)
// 		return (init_token(TOKEN_OPERATION, value));
// 	return (init_token(TOKEN_IDENTIFIER, value));
// }

// might need to exclude capital chars here.. if label
// and identifier is supposed to be the same thing..?? 
t_token			*lex_get_identifier(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	if (!(value = ft_memalloc(sizeof(char))))
		return (NULL);
	while (ft_isalnum(lexer->c) || lexer->c == '_')
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strlcat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	return (init_token(TOKEN_IDENTIFIER, value));
}

t_token			*lex_get_string(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	lex_advance(lexer);
	if (!(value = ft_memalloc(sizeof(char))))
		return (NULL);
	while (lexer->c != '"')
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strncat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	lex_advance(lexer);
	return (init_token(TOKEN_STRING, value));
}

char			*char_to_string(char c)
{
	char	*str;

	if (!(str = ft_strnew(sizeof(char))))
		return (NULL);
	*str = c;
	return str;
}

t_token			*lex_get_newline(t_lexer *lexer)
{
	lex_advance(lexer);
	// if (lexer->c != 10)
	// 	return (init_token(TOKEN_ILLEGAL, char_to_string(lexer->c)));
	// lex_advance(lexer);
	lexer->line_number++;
	lexer->column = 1;
	return (init_token(TOKEN_NEWLINE, "\\n"));
}

t_token			*lex_advance_with_token(t_lexer *lexer, t_token *token)
{
	lex_advance(lexer);
	return (token);
}

t_token			*lex_get_operator(t_lexer *lexer)
{
	if (lexer->c == LABEL_CHAR)
		return (lex_advance_with_token(lexer,
				init_token(TOKEN_COLON, char_to_string(lexer->c))));
	if (lexer->c == DIRECT_CHAR)
		return (lex_advance_with_token(lexer,
				init_token(TOKEN_DIRECT, char_to_string(lexer->c))));
	if (lexer->c == SEPARATOR_CHAR)
		return (lex_advance_with_token(lexer,
				init_token(TOKEN_SEPARATOR, char_to_string(lexer->c))));
	if (lexer->c == '\n')
		return (lex_get_newline(lexer));
		// return (lex_advance_with_token(lexer,
		// 		init_token(TOKEN_NEWLINE, char_to_string(lexer->c))));
	return (init_token(TOKEN_ILLEGAL, char_to_string(lexer->c)));
}

int		is_operator(char c)
{
	if (c == LABEL_CHAR || c == DIRECT_CHAR ||
		c == SEPARATOR_CHAR || c == NEWLINE_CHAR)
		return (1);
	return (0);
}

t_token			*lex_get_next_token(t_lexer *lexer)
{
	while (lexer->c && lexer->index < lexer->size)
	{
		if (lexer->c == ' ' || lexer->c == '\t')
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
	return (init_token(TOKEN_EOF, "\0"));
}

void			free_lexer(t_lexer **lexer)
{
	free(*lexer);
	*lexer = NULL;
}
