/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:57:54 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/02 11:03:25 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <stdio.h>

t_token			*init_token(t_type type, char *value)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

void			free_token(t_token **token)
{
	free(*token);
	*token = NULL;
}

// This is a bad idea, as this function is refering to
// enum values defined in token.h
int				is_opcode(t_type type)
{
	if (type >= 0 && type <= 15)
		return (1);
	return (0);
}
