/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:15:35 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/24 12:26:44 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "error.h"
#include "encoder.h"
#include "opcodes.h"
#include "file.h"

t_ast	*compound_insert(t_ast *compound, t_ast *new)
{
	t_ast	**tmp;

	compound->compound_size += 1;
	if (!(tmp = realloc(compound->compound_value,
					compound->compound_size * sizeof(t_ast *))))
		return (NULL);
	tmp[compound->compound_size - 1] = new;
	compound->compound_value = tmp;
	return (compound);
}
