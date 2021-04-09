/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:48:04 by seronen           #+#    #+#             */
/*   Updated: 2021/04/09 19:16:59 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int		convert_4_bytes(unsigned char *data)
{
	return ((data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]);
	return (0);
}

int		calc_argtype_size(t_stmt *stmt)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (i < opcode_table[stmt->statement - 1].argument_amount)
	{
		if (stmt->arg_types[i] == T_REG)
			size += 1;
		else if (stmt->arg_types[i] == T_DIR &&
			opcode_table[stmt->statement - 1].dir_size == 4)
			size += 4;
		else if (stmt->arg_types[i])
			size += 2;
		i++;
	}
	return (size);
}

int		decrypt_arg_type(t_stmt *stmt, int counter, int z)
{
	int oct;

	oct = stmt->arg_type;
	while (z > 0 && counter < 3)
	{
		if (oct & z)
		{
			z >>= 1;
			if (oct & z)
				stmt->arg_types[counter] = T_IND;
			else
				stmt->arg_types[counter] = T_DIR;
		}
		else
		{
			z >>= 1;
			if (oct & z)
				stmt->arg_types[counter] = T_REG;
			else
				stmt->arg_types[counter] = 0;
		}
		z >>= 1;
		counter++;
	}
	return (calc_argtype_size(stmt));
}

int		validate_arg_type(t_stmt *stmt, int i)
{
	int val;
	int aim;

	while (i < opcode_table[stmt->statement - 1].argument_amount)
	{
		val = stmt->arg_types[i];
		aim = opcode_table[stmt->statement - 1].argument_types[i];
		if (!val)
			return (1);
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
		size += decrypt_arg_type(carry->stmt, 0, 128) + 1;
	else
	{
		carry->stmt->arg_types[0] = T_DIR;
		size += opcode_table[carry->stmt->statement - 1].dir_size;
		return (size);
	}
	if (validate_arg_type(carry->stmt, 0))
		return (stmt_error(carry, size, arena));
	return (size);
}
