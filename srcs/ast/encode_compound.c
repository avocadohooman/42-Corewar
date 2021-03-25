/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_compound.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:13:11 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 13:47:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*encode_compound(t_ast *compound)
{
	int				i;
	t_buf			*buf;
	t_buf			*data;

	if (!(buf = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	i = -1;
	while (++i < compound->compound_size)
	{
		if (compound->compound_value[i]->type == AST_HEADER)
		{
			if (!(data = encode_header(compound->compound_value[i])) ||
				!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
		else if (compound->compound_value[i]->type == AST_BODY)
		{
			if (!(data = encode_body(compound->compound_value[i])) ||
				!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
	}
	return (buf);
}
