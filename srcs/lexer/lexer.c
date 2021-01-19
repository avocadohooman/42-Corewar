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

t_lexer			*init_lexer(char *data, size_t size)
{
	t_lexer *lexer;

	if (!(lexer = ft_memalloc(sizeof(t_lexer))))
		return (NULL);
	lexer->data = data;
	lexer->size = size;
	lexer->index = 0;
	lexer->c = data[0];
	lexer->line_number = 0;
}

void			lex_advance(t_lexer *lexer)
{
	if (lexer->index < lexer->size)
	{
		lexer->index++;
		lexer->c = lexer->data[lexer->index];
	}
}

void			lex_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lex_advance(lexer);
}

void			lex_skip_comment(t_lexer *lexer)
{
	while (lexer->c != '\n')
		lex_advance(lexer);
}

t_token			*lex_get_command(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	int		len;

	if (!(value = ft_memalloc(sizeof(char))))
		return (NULL);
	while (ft_isalpha(lexer->c))
	{
		len = ft_strlen(value);
		if (!(tmp = realloc(value, len + 2)))
			return (NULL);
		ft_strlcat(tmp, &lexer->c, len + 2);
		value = tmp;
		lex_advance(lexer);
	}
	lex_advance(lexer);
	if (!(ft_memcmp(value, NAME_CMD_STRING, len + 2)))
		return (init_token(COMMAND_NAME, value));
	else if (!(ft_memcmp(value, COMMENT_CMD_STRING, len + 2)))
		return (init_token(COMMAND_NAME, value));
	return (init_token(TOKEN_ILLEGAL, value));
}

// the order of the opcode_table and t_type enums are now dependent
// on eachother. The opcodes must come first in the enum list and
// should be presented in the same order as in the opcode_table
t_token			*lex_get_keyword(char *value, size_t size)
{
	char	**opcode_table;
	int		i;

	opcode_table = (char*[20]){
		LFORK_LITERAL, STI_LITERAL, FORK_LITERAL, LLD_LITERAL,
		LD_LITERAL, ADD_LITERAL, ZJMP_LITERAL, SUB_LITERAL,
		LDI_LITERAL, OR_LITERAL, ST_LITERAL, AFF_LITERAL,
		LIVE_LITERAL, XOR_LITERAL, LLDI_LITERAL, AND_LITERAL,
		NULL
	};
	i = 0;
	while (opcode_table[i])
	{
		if (!ft_memcmp(value, opcode_table[i], size))
			return (init_token(i, value));
		i++;
	}
	return (init_token(TOKEN_IDENTIFIER, value));
}

// might need to exclude capital chars here.. if label
// and identifier is supposed to be the same thing..?? struggless
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
	return (lex_get_keyword(value, len + 2));
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
		ft_strlcat(tmp, &lexer->c, len + 2);
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

t_token			*lex_get_operator(t_lexer *lexer)
{
	if (lexer->c == LABEL_CHAR)
		return (init_token(TOKEN_COLON, char_to_string(lexer->c)));
	if (lexer->c == DIRECT_CHAR)
		return (init_token(TOKEN_DIRECT, char_to_string(lexer->c)));
	if (lexer->c == SEPARATOR_CHAR)
		return (init_token(TOKEN_SEPARATOR, char_to_string(lexer->c)));
	if (lexer->c == NEWLINE_CHAR && ++(lexer->line_number))
		return (init_token(TOKEN_NEWLINE, char_to_string(lexer->c)));
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
