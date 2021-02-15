/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:29:33 by seronen           #+#    #+#             */
/*   Updated: 2021/02/15 23:36:44 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int     stmt_error(t_carriage *carry, int step, unsigned char *arena)
{
	free(carry->stmt);
	carry->stmt = NULL;
	carry->next_statement = 0;
	carry->pos = fetch_position(arena, carry->abs_pos, step, MEM_SIZE);
	carry->abs_pos = real_modulo(carry->abs_pos, step, MEM_SIZE);
	return (0);
}

int		init_stmt(t_carriage *carry)
{
	t_stmt *stmt;

	if (!(stmt = (t_stmt*)malloc(sizeof(t_stmt))))
		print_error(MALLOC);
	carry->stmt = stmt;
	carry->stmt->statement = carry->pos[0];
	if (carry->stmt->statement > OPCODE_AMOUNT || carry->stmt->statement < 1)
		return (1);
	carry->stmt->arg_type = carry->pos[1];
	ft_bzero(carry->stmt->arg_types, sizeof(int) * 3);
	ft_bzero(carry->stmt->args, sizeof(int) * 3);
	return (0);
}

int     form_statement(t_carriage *carry, unsigned char *arena)
{
	int size;

	carry->abs_pos += carry->next_statement;
	if (init_stmt(carry))
		return (stmt_error(carry, 1, arena));
	size = decrypt(carry, arena);
	if (!size)
		return (0);
	get_args(carry, 1);
	carry->cycles_to_execute = opcode_table[carry->stmt->statement - 1].cost;
	carry->pos = fetch_position(arena, carry->abs_pos, size, MEM_SIZE);
	carry->next_statement = size;
	return (0);
}
