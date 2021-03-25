/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visit_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:16:41 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/25 13:42:52 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*encode_instruction(t_ast *instruction)
{
	int i;

	i = -1;
	while (++i < instruction->compound_size)
	{
		if (instruction->compound_value[i]->type == AST_STATEMENT)
			return (encode_statement(instruction->compound_value[i]));
	}
	return ((t_buf *)ft_memalloc(sizeof(t_buf)));
}
