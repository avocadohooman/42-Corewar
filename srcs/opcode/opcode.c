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
#include <stdio.h>

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

int		check_argument(int options, int received)
{
	if ((options & received) == received)
		return (1);
	return (0);
}

void	opcode_parse(t_parser *parser)
{
	int			opcode;
	int			i;
	t_opcode	code;

	if ((opcode = lookup_opcode(parser->prev_token->value)) < 0)
		return ; // error
	code = opcode_table[opcode];
	parser_parse_body_arg(parser, code.argument_types[0]);
	i = 1;
	while (i < code.argument_amount)
	{
		parser_consume(parser, TOKEN_SEPARATOR);
		parser_parse_body_arg(parser, code.argument_types[i]);
		i++;
	}
}
