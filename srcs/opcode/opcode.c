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

t_ast	*opcode_parse(t_parser *parser)
{
	int			opcode;
	int			i;
	t_opcode	code;
	t_ast		*statement;

	if ((opcode = lookup_opcode(parser->prev_token->value)) < 0)
		parser_exit_with_message(ERROR_UNKNOWN_STATEMENT);
	code = opcode_table[opcode];
	if (!(statement = init_ast(AST_STATEMENT)))
		return (NULL);
	statement->statement = (char)opcode;
	statement->statement_size = 1 + opcode_table[opcode].argument_type;
	if (!(statement->statement_args = ft_memalloc(sizeof(t_ast *) * code.argument_amount)))
		return (NULL);
	if (!(statement->statement_args[0] = parser_parse_body_arg(parser, code.argument_types[0])))
		return (NULL);
	statement->statement_size += statement->statement_args[0]->arg_size;
	if (statement->statement_args[0]->arg_type == T_DIR && code.dir_size == 4)
	{
		printf("HELLOOOOOOOO]\n");
		statement->statement_size += 2;
		statement->statement_args[0]->arg_size = 4;
	}
	i = 1;
	while (i < code.argument_amount)
	{
		parser_consume(parser, TOKEN_SEPARATOR);
		if (!(statement->statement_args[i] = parser_parse_body_arg(parser, code.argument_types[i])))
			return (NULL);
		statement->statement_size += statement->statement_args[i]->arg_size;
		if (statement->statement_args[i]->arg_type == T_DIR && code.dir_size == 4)
		{
			statement->statement_size += 2;
			statement->statement_args[i]->arg_size = 4;
		}
		i++;
	}
	statement->statement_n_args = code.argument_amount;
	return (statement);
}
