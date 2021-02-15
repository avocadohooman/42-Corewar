/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:48:04 by seronen           #+#    #+#             */
/*   Updated: 2021/02/16 01:07:44 by seronen          ###   ########.fr       */
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
	return (0);
}

int		calc_argtype_size(t_stmt *stmt)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (i < 3)
	{
		if (!stmt->arg_types[i])
			break ;
		if (stmt->arg_types[i] == T_REG)
			size += 1;
		else if (stmt->arg_types[i] == T_DIR && opcode_table[stmt->statement - 1].dir_size == 4)
			size += 4;
		else
			size += 2;
		i++;
	}
	return (size);
}

int		decrypt_arg_type(t_stmt *stmt, int counter)
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
	return (calc_argtype_size(stmt));
}

int		validate_arg_type(t_stmt *stmt, int i)
{
	int val;
	int aim;

	while (i < 3)
	{
		val = stmt->arg_types[i];
		aim = opcode_table[stmt->statement - 1].argument_types[i];
		if ((val & aim) != val)
			return (1);
		i++;
	}
	return (0);
}

int		decrypt(t_carriage *carry, unsigned char *arena)
{
	int size;

	size = 1;
	if (opcode_table[carry->stmt->statement - 1].argument_type)
		size += decrypt_arg_type(carry->stmt, 0) + 1;
	else
	{
		carry->stmt->arg_types[0] = T_DIR;
		size += opcode_table[carry->stmt->statement - 1].dir_size;
		return (size);
	}
	if (validate_arg_type(carry->stmt, 0))
	{
		printf("Invalid argument type code!\n");
		return (stmt_error(carry, size, arena));
	}
	return (size);
}