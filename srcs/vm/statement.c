/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:29:33 by seronen           #+#    #+#             */
/*   Updated: 2021/04/15 16:28:31 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int		stmt_error(t_carriage *carry, int step)
{
	free(carry->stmt);
	carry->stmt = NULL;
	carry->next_statement = 0;
	carry->cycles_to_execute = -1;
	carry->abs_pos = real_modulo(carry->abs_pos, step, MEM_SIZE);
	return (0);
}

int		validate_regs(t_carriage *carry, int i, int size)
{
	while (i < 3)
	{
		if (carry->stmt->arg_types[i] == T_REG)
		{
			if (carry->stmt->args[i] < 1 || carry->stmt->args[i] > 16)
			{
				stmt_error(carry, size);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		init_stmt(t_carriage *carry, unsigned char *arena)
{
	t_stmt *new;

	if (!(new = (t_stmt*)malloc(sizeof(t_stmt))))
		print_error(MALLOC);
	carry->abs_pos = real_modulo(carry->abs_pos,
		carry->next_statement, MEM_SIZE);
	carry->stmt = new;
	carry->stmt->statement = arena[carry->abs_pos];
	if (carry->stmt->statement > OPCODE_AMOUNT || carry->stmt->statement < 1)
	{
		stmt_error(carry, 1);
		return (1);
	}
	carry->cycles_to_execute = g_opcode_table[carry->stmt->statement - 1].cost;
	ft_bzero(carry->stmt->arg_types, sizeof(int) * 3);
	ft_bzero(carry->stmt->args, sizeof(int) * 3);
	return (0);
}

int		form_statement(t_carriage *carry, unsigned char *arena)
{
	int size;

	carry->stmt->arg_type = arena[real_modulo(carry->abs_pos, 1, MEM_SIZE)];
	size = decrypt(carry);
	if (!size)
		return (1);
	if (g_opcode_table[carry->stmt->statement - 1].argument_type)
		get_args(carry, arena, real_modulo(carry->abs_pos, 2, MEM_SIZE));
	else
		get_args(carry, arena, real_modulo(carry->abs_pos, 1, MEM_SIZE));
	if (validate_regs(carry, 0, size))
		return (1);
	carry->next_statement = size;
	return (0);
}
