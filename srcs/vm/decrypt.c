/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:48:04 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 12:51:42 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h> // DELETE
#include "opcodes.h"

int		convert_4_bytes(unsigned char *data)
{
	// Converts 4 individual bytes to an int, counting for endianness
	// Big endian to little endian

	return ((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
}

void	decrypt_arg_type(t_stmt *stmt, int counter)
{
	// Cycles through bits in arg_type_code and finds arg types for each arg
	// Includes types in arg_types array carriage->arg_types[3]
	// Reviews two bits at a time

	// 01 is T_REG
	// 10 is T_DIR
	// 11 is T_IND

	int z = 128;	// ????
	int oct = stmt->arg_type;

	while (z > 0)
	{
		if (oct & z)	// if bit is 1
		{
			z >>= 1;	// next bit
			if (oct & z)	// if bit is 1
				stmt->arg_types[counter] = T_IND;
			else
				stmt->arg_types[counter] = T_DIR;
		}
		else
		{
			z >>= 1;	// next bit
			if (oct & z)	// if bit is 1
				stmt->arg_types[counter] = T_REG;
			else
				stmt->arg_types[counter] = 0;
		}
		z >>= 1;	// next bit
		counter++;	// counter to keep up with carriage->arg_types[3] array
	}
}

void	init_stmt(t_carriage *carry)
{
	t_stmt *stmt;

	if (!(stmt = (t_stmt*)malloc(sizeof(t_stmt))))
	{
		printf("MALLOC ERROR!!!!! vm/init_stmt\n");
		exit(-42);
	}
	stmt->statement = carry->pos[0];
	stmt->arg_type = carry->pos[1];
	ft_bzero(stmt->arg_types, sizeof(int) * 3);
	carry->stmt = stmt;
}

int		read_arg(unsigned char *mem, int type, int pos, unsigned char stmt)
{
	if (type == T_REG)
		return ((int)mem[pos]);						// convert 1 byte to an int
	else if (type == T_DIR && opcode_table[stmt - 1].dir_size == 4)
		return (convert_4_bytes(&mem[pos]));			// convert 4 bytes to an int
	else
		return ((mem[pos] << 8) + mem[pos + 1]);		// convert 2 bytes to an int
}

int		get_args(t_carriage *carry, int pos)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (!carry->stmt->arg_types[i])		// Dont read if no arg, no arg type so no arg...
			break ;
		carry->stmt->args[i] = read_arg(carry->pos,
			carry->stmt->arg_types[i], pos, carry->stmt->statement); 	// read arg and save it to args array
		if (carry->stmt->arg_types[i] == T_REG)		// increment position
			pos += 1;
		else if (carry->stmt->arg_types[i] == T_DIR &&
			opcode_table[carry->stmt->statement - 1].dir_size == 4) 		// increment position
			pos += 4;
		else
			pos += 2;			// increment position
		i++;
	}
	return (pos);
}

int     form_statement(t_carriage *carry)
{
	int pos;

    init_stmt(carry);		// Init statement, mallocs and sets the statement
	pos = 1;
	if (opcode_table[carry->stmt->statement - 1].argument_type) // If arg_type is true
	{
		decrypt_arg_type(carry->stmt, 0); // zero param is just a counter :) saves lines!
		pos++;
	}
	else
		carry->stmt->arg_types[0] = T_DIR;	// Resolve single arg issue when no arg type present
											// Only case when no arg_type_code is when first and only arg is T_DIR
	carry->pos += get_args(carry, pos);		// Update carriage "PC" to the next statement
	carry->offset = convert_4_bytes(carry->pos);
	carry->cycles_to_execute = opcode_table[carry->stmt->statement - 1].cost; // Set "cost" (cycles to pass until execution can happen)
	printf("Next statement code: %02x\n", carry->pos[0]);
	printf("Statement code: %02x, numerical: %d\n", carry->stmt->statement, carry->stmt->statement);
	printf("Cycles until execution (cost): %d\n", carry->cycles_to_execute);
	printf("Arguments and types:\n");
	int i = 0;
	while (i < 3)
	{
		if (carry->stmt->arg_types[i])
			printf("ARG %d == type %d –– value: %d\n", i + 1, carry->stmt->arg_types[i], carry->stmt->args[i]);
		else
			printf("No arg %d!\n", i + 1);
		i++;
	}
	printf("\n");
	return (0);
}