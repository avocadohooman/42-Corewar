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

t_lexer			*init_lexer(char *data, size_t size)
{
    t_lexer *lexer;

    if (!(lexer = ft_memalloc(sizeof(t_lexer))))
        return (NULL);
    lexer->data = data;
    lexer->size = size;
    lexer->index = 0;
    lexer->c = data[0];
}

void			lex_advance(t_lexer *lexer)
{
    if (lexer->index < lexer->size)
    {
        lexer->index++;
        lexer->c = lexer->data[lexer->index];
    }
}

void            lex_skip_whitespace(t_lexer *lexer)
{
    while (lexer->c == ' ' || lexer->c == '\t')
        lex_advance(lexer);
}

t_token         *lex_get_identifier(t_lexer *lexer)
{
    char    *value;
    char    *tmp;

    if (!(value = ft_memalloc(sizeof(char))))
        return (NULL);
    while (ft_isalnum(lexer->c))
    {
        if (!(tmp = realloc(value, ft_strlen(value) + 2)))
            return (NULL);
        ft_strlcat(tmp, &lexer->c, ft_strlen(value) + 2);
        value = tmp;
        lex_advance(lexer);
    }
    return (init_token(TOKEN_IDENTIFIER, value));
}

t_token         *lex_get_string(t_lexer *lexer)
{}

t_token			*lex_get_next_token(t_lexer *lexer)
{
    while (lexer->c && lexer->index < lexer->size)
    {
        if (lexer->c == ' ' || lexer->c == '\t')
            lex_skip_whitespace(lexer);
        if (ft_isalnum(lexer->c))
            return (lex_get_identifier(lexer));
        if (lexer->c == '"')
            return (lex_get_string(lexer));
    }
    return (init_token(TOKEN_EOF, "\0"));
}

void			free_lexer(t_lexer **lexer)
{
    free(*lexer);
    *lexer = NULL;
}
