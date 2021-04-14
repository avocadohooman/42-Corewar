/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:05:04 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:05:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token			*init_token(t_type type, char *value)
{
	t_token	*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

void			token_free(t_token **token)
{
	if (*token)
	{
		free((*token)->value);
		(*token)->value = NULL;
		free(*token);
		*token = NULL;
	}
}
