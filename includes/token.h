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
	TOKEN_ILLEGAL,
	TOKEN_STRING,
	TOKEN_LABEL,
	TOKEN_INSTRUCTION,
	TOKEN_REGISTER,
	TOKEN_SEPARATOR,
	TOKEN_DIRECT_LABEL,
	TOKEN_DIRECT
}				t_type;

typedef struct	s_token
{
	char		*value;
	size_t		size;
}				t_token;

t_token			*init_token(t_type type, char *value);
void			free_token(t_token **token);

#endif