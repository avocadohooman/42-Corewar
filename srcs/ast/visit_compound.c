/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit_compound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:13:11 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 12:29:29 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*visit_compound(t_ast *compound)
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
			if (!(data = visit_header(compound->compound_value[i])) ||
				!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
		else if (compound->compound_value[i]->type == AST_BODY)
		{
			if (!(data = visit_body(compound->compound_value[i])) ||
				!(buf_insert(buf, data->data, data->used)))
				return (NULL);
			buf_free(&data);
		}
	}
	return (buf);
}
