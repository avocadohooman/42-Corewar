/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_body.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:17:14 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 13:41:42 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*encode_body(t_ast *body)
{
	int		i;
	t_buf	*buf_body;
	t_buf	*buf_instruction;

	if (!(buf_body = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = -1;
	while (++i < body->compound_size)
	{
		if (body->compound_value[i]->type == AST_EMPTY)
			continue ;
		if (!(buf_instruction = encode_instruction(body->compound_value[i])))
			return (NULL);
		if (!(buf_insert(buf_body, buf_instruction->data,
			buf_instruction->used)))
			return (NULL);
		buf_free(&buf_instruction);
	}
	return (buf_body);
}
