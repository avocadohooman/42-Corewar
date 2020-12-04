/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:08:55 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/01 21:15:30 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include "libft.h"

typedef enum	e_type
{
	OPCODE_LFORK,
	OPCODE_STI,
	OPCODE_FORK,
	OPCODE_LLD,
	OPCODE_LD,
	OPCODE_ADD,
	OPCODE_ZJMP,
	OPCODE_SUB,
	OPCODE_LDI,
	OPCODE_OR,
	OPCODE_ST,
	OPCODE_AFF,
	OPCODE_LIVE,
	OPCODE_XOR,
	OPCODE_LLDI,
	OPCODE_AND,

	COMMAND_NAME,
	COMMAND_COMMENT,
	COMMAND_UNKNOWN,

	TOKEN_EOF,
	TOKEN_IDENTIFIER,
	TOKEN_STRING,
	TOKEN_OPERATOR,
	TOKEN_ILLEGAL,

	TOKEN_COLON,
	TOKEN_DIRECT,
	TOKEN_SEPARATOR,
	TOKEN_NEWLINE
}				t_type;

typedef struct	s_token
{
	char		*value;
	t_type		type;
}				t_token;

t_token			*init_token(t_type type, char *value);
void			free_token(t_token **token);

int				is_opcode(t_type type);

#endif