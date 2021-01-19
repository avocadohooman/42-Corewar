/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:08:55 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/19 12:23:14 by npimenof         ###   ########.fr       */
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
	TOKEN_OPERATION,
	TOKEN_REGISTRY,
	TOKEN_NUMBER,

	TOKEN_COLON,
	TOKEN_DIRECT,
	TOKEN_SEPARATOR,
	TOKEN_NEWLINE,

	TOKEN_EOF,
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