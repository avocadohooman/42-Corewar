/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:09:40 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:09:50 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_buf	*encode_ast(t_ast *ast)
{
	if (ast->type == AST_COMPOUND)
		return (encode_compound(ast));
	return (NULL);
}
