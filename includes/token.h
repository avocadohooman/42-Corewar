/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:08:55 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/25 09:31:06 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "libft.h"

typedef enum	e_type
{
	TOKEN_ILLEGAL,
	TOKEN_COMMAND,
	TOKEN_STRING,

	TOKEN_IDENTIFIER,
	TOKEN_NEGATIVE,

	TOKEN_COLON,
	TOKEN_DIRECT,
	TOKEN_SEPARATOR,
	TOKEN_NEWLINE,

	TOKEN_EOF,
}				t_type;

static const char	*g_token_literal[] = {
	[TOKEN_ILLEGAL] = "ILLEGAL",
	[TOKEN_COMMAND] = "COMMAND",
	[TOKEN_STRING] = "STRING",
	[TOKEN_IDENTIFIER] = "IDENTIFIER",
	[TOKEN_NEGATIVE] = "NEGATIVE",
	[TOKEN_COLON] = "INDIRECT",
	[TOKEN_DIRECT] = "DIRECT",
	[TOKEN_SEPARATOR] = "SEPARATOR",
	[TOKEN_NEWLINE] = "NEWLINE",
	[TOKEN_EOF] = "EOF",
};

typedef struct	s_token
{
	char		*value;
	t_type		type;
}				t_token;

t_token			*init_token(t_type type, char *value);
void			free_token(t_token **token);

int				is_opcode(t_type type);

#endif