/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:48:04 by seronen           #+#    #+#             */
/*   Updated: 2021/02/04 15:52:45 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h> // DELETE
#include "opcodes.h"

void	decrypt_arg_type(t_stmt *stmt, int counter)
{
	int z = 128;
	int oct = stmt->arg_type;

	while (z > 0)
	{
		if (oct & z)
		{
			z >>= 1;
			if (oct & z)
			{
				printf("Arg was T_IND\n");
				stmt->arg_types[counter] = T_IND;
			}
			else
			{
				printf("Arg was T_DIR\n");
				stmt->arg_types[counter] = T_DIR;
			}
		}
		else
		{
			z >>= 1;
			if (oct & z)
			{
				printf("Arg was T_REG\n");
				stmt->arg_types[counter] = T_REG;
			}
			else
			{
				printf("Arg was NONE\n");
				stmt->arg_types[counter] = 0;
			}
		}
		z >>= 1;
		counter++;
	}
}

void	init_statement(t_carry *carry)
{
	t_stmt *stmt;

	if (!(stmt = (t_stmt*)malloc(sizeof(t_stmt))))
	{
		printf("MALLOC ERROR!!!!!\n");
		exit(-42);
	}
	stmt->statement = carry->pos[0];
	stmt->arg_type = carry->pos[1];
	ft_bzero(stmt->arg_types, sizeof(int) * 3);
	carry->statement = stmt;
}

int		read_arg(unsigned char *mem, int type, int *pos, unsigned char stmt)
{
	int to_read;

	to_read = 0;
	if (type == T_REG)
		return ((int)mem[*pos]);
	else if (type == T_DIR)
		to_read = opcode_table[stmt].dir_size;
	else if (type == T_IND)
		to_read = 2;
}

void	get_args(t_carry *carry, int pos)
{
	int i;

	i = 0;
	while (i < 3)
	{
		carry->statement->args[i] = read_arg(carry->pos,
			carry->statement->arg_types[i], &pos, carry->statement->statement);
		printf("read_arg returned: %d\n", carry->statement->args[i]);
		i++;
	}
}

int     form_statement(t_vm *vm, t_carry *carry)
{
	int pos;

    init_statement(carry);
	pos = 1;
	if (opcode_table[carry->statement->statement].argument_type)
	{
		decrypt_arg_type(carry->statement, 0); // zero param is just a counter :) saves lines!
		pos++;
	}
	get_args(carry, pos);
}