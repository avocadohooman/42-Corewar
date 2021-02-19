/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:29:33 by seronen           #+#    #+#             */
/*   Updated: 2021/02/19 16:47:51 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int     stmt_error(t_carriage *carry, int step, unsigned char *arena)
{
	free(carry->stmt);
	carry->stmt = NULL;
	carry->next_statement = 0;
	carry->cycles_to_execute = 0;
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

int		init_stmt(t_carriage *carry, unsigned char *arena)
{
	t_stmt *new;

	if (!(new = (t_stmt*)malloc(sizeof(t_stmt))))
		print_error(MALLOC);
	carry->abs_pos += carry->next_statement;
	carry->stmt = new;
	carry->stmt->statement = arena[carry->abs_pos];
	if (carry->stmt->statement > OPCODE_AMOUNT || carry->stmt->statement < 1)
	{
		stmt_error(carry, 1, arena);
		return (1);
	}
	carry->cycles_to_execute = opcode_table[carry->stmt->statement - 1].cost;
	ft_bzero(carry->stmt->arg_types, sizeof(int) * 3);
	ft_bzero(carry->stmt->args, sizeof(int) * 3);
	return (0);
}

int     form_statement(t_carriage *carry, unsigned char *arena)
{
	int size;

	carry->stmt->arg_type = arena[real_modulo(carry->abs_pos, 1, MEM_SIZE)];
	size = decrypt(carry, arena);
	if (!size)
		return (1);
	if (opcode_table[carry->stmt->statement - 1].argument_type)
		get_args(carry, arena, real_modulo(carry->abs_pos, 2, MEM_SIZE));
	else
		get_args(carry, arena, real_modulo(carry->abs_pos, 1, MEM_SIZE));
	if (validate_regs(carry, arena, 0, size))
		return (1);
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
