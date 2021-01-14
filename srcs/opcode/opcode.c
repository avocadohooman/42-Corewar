/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:44:22 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/13 19:23:27 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "opcodes.h"

int		lookup_opcode(char *str)
{
	int		i;

	i = 0;
	while (opcode_table[i].literal)
	{
		if (!ft_strcmp(opcode_table[i].literal, str))
			return (i);
		i++;
	}
	return (-1);
}

void	opcode_parse(t_parser *parser)
{
	int		index;

	if ((index = lookup_opcode(parser->prev_token->value)) < 0)
		return ;
	// parser_consume(parser, TOKEN_IDENTIFIER);
	// if (parser->current_token->type == TOKEN_COLON)
	// 	return ; // parse_label_definition.
	opcode_table[index].parse(parser);
}
