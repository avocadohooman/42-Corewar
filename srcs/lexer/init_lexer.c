/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:29:53 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 13:46:16 by Gerhard          ###   ########.fr       */
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
	lexer->line_number = 1;
	lexer->column = 1;
	return (lexer);
}
