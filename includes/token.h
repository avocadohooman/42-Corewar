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
// # include "opcodes.h"

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

// static char		*g_opcode_table[17] = {
// 	[OPCODE_LFORK] = LFORK_LITERAL,
// 	[OPCODE_STI] = STI_LITERAL,
// 	[OPCODE_FORK] = FORK_LITERAL,
// 	[OPCODE_LLD] = LLD_LITERAL,
// 	[OPCODE_LD] = LD_LITERAL,
// 	[OPCODE_ADD] = ADD_LITERAL,
// 	[OPCODE_ZJMP] = ZJMP_LITERAL,
// 	[OPCODE_SUB] = SUB_LITERAL,
// 	[OPCODE_LDI] = LDI_LITERAL,
// 	[OPCODE_OR] = OR_LITERAL,
// 	[OPCODE_ST] = ST_LITERAL,
// 	[OPCODE_AFF] = AFF_LITERAL,
// 	[OPCODE_LIVE] = LIVE_LITERAL,
// 	[OPCODE_XOR] = XOR_LITERAL,
// 	[OPCODE_LLDI] = LLDI_LITERAL,
// 	[OPCODE_AND] = AND_LITERAL
// };

#endif