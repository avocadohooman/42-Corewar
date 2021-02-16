/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:29:33 by seronen           #+#    #+#             */
/*   Updated: 2021/02/16 03:20:04 by seronen          ###   ########.fr       */
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

int		validate_regs(t_carriage *carry, unsigned char *arena, int i, int size)
{
	while (i < 3)
	{
		if (carry->stmt->arg_types[i] == T_REG)
			if (carry->stmt->args[i] < 1 || carry->stmt->args[i] > 16)
			{
				stmt_error(carry, size, arena);
				return (1);
			}
		i++;
	}
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
	{
//		printf("Invalid statement code: %02x\n", carry->pos[0]);
//		printf("Abs pos: %d\n", carry->abs_pos);
		return (stmt_error(carry, 1, arena));
	}
//	printf("Valid statement code: %02x\n", carry->pos[0]);
//	printf("Abs pos: %d\n", carry->abs_pos);
	size = decrypt(carry, arena);
	if (!size)
		return (0);
	get_args(carry, 1);
	if (validate_regs(carry, arena, 0, size))
		return (0);
	carry->cycles_to_execute = opcode_table[carry->stmt->statement - 1].cost;
	carry->pos = fetch_position(arena, carry->abs_pos, size, MEM_SIZE);
	carry->next_statement = size;

	// End of code -> Printing
	/*
	printf("\nCarriage ID: %d\nPlayer: %d\n", carry->id, carry->regs[0] * -1);
	printf("Absolute index of carry: %d\n", carry->abs_pos);
	printf("Statement code: %s\n", opcode_table[carry->stmt->statement - 1].literal);
	printf("Cycles until execution (cost): %d\n", carry->cycles_to_execute);
	if (carry->pos[0] > 0 && carry->pos[0] < 17)
		printf("Next statement code: %s\n", opcode_table[carry->pos[0] - 1].literal);
	printf("Arguments and types:\n");
	int i = 0;
	while (i < 3)
	{
		if (carry->stmt->arg_types[i])
			printf("ARG %d == type %d –– value: %d\n", i + 1, carry->stmt->arg_types[i], carry->stmt->args[i]);
		else
			printf("No arg %d!\n", i + 1);
		i++;
	}
	printf("\n"); */
	return (0);
}
