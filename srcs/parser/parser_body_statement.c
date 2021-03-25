/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_body_statement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:21:16 by npimenof          #+#    #+#             */
/*   Updated: 2021/03/25 16:19:24 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast	*new_statement(t_parser *parser, t_label **labels, t_opcode code)
{
	t_ast	*statement;

	if (!(statement = init_ast(AST_STATEMENT)))
		return (NULL);
	statement->label_list = *labels;
	statement->statement = (char)code.statement_code;
	statement->statement_position = parser->bytes;
	statement->statement_size =  1 + code.argument_type;
	statement->statement_n_args = code.argument_amount;
	return (statement);
}

int		argument_size(t_ast *arg, t_opcode code)
{
	if (arg->arg_type == T_DIR)
		arg->arg_size = code.dir_size;
	return (arg->arg_size);
}

t_ast	*parser_parse_body_args(t_parser *parser, t_ast *stmt, t_opcode code)
{
	int	i;

	i = -1;
	while (++i < code.argument_amount)
	{
		if (!(stmt->statement_args[i] =
				parser_parse_body_arg(parser, code.argument_types[i])))
			return (NULL);
		stmt->statement_size += argument_size(stmt->statement_args[i], code);
		if (i < code.argument_amount - 1)
			parser_consume(parser, TOKEN_SEPARATOR);
	}
	return (stmt);
}

t_ast	*parser_parse_body_statement(t_parser *parser, t_label **labels)
{
	int			opcode;
	int			i;
	t_opcode	code;
	t_ast		*stmt;

	if ((opcode = lookup_opcode(parser->prev_token->value)) < 0)
		parser_exit_with_message(parser, ERROR_UNKNOWN_STATEMENT);
	code = opcode_table[opcode];
	if (!(stmt = new_statement(parser, labels, code)))
		return (NULL);
	if (!(stmt->statement_args =
			ft_memalloc(sizeof(t_ast *) * code.argument_amount)))
		return (NULL);
	return (parser_parse_body_args(parser, stmt, code));
}
