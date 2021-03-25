/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:08:10 by seronen           #+#    #+#             */
/*   Updated: 2021/02/16 19:28:22 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int		read_arg(unsigned char *mem, int type, int pos, unsigned char stmt)
{
	if (type == T_REG)
		return ((int)mem[pos]);						// convert 1 byte to an int
	else if (type == T_DIR && opcode_table[stmt - 1].dir_size == 4)
		return (read_bytes(mem, pos, 4));			// convert 4 bytes to an int
	else
		return ((short)read_bytes(mem, pos, 2));		// convert 2 bytes to an int
}

int		get_args(t_carriage *carry, unsigned char *arena, int abs_pos)
{
	int i;
	int pos;
	int step;

	i = 0;
	pos = abs_pos;
	while (i < 3)
	{
		if (!carry->stmt->arg_types[i])		// Dont read if no arg, no arg type so no arg...
			break ;
		carry->stmt->args[i] = read_arg(arena, carry->stmt->arg_types[i], pos, carry->stmt->statement);
		if (carry->stmt->arg_types[i] == T_REG)		// increment position
			step = 1;
		else if (carry->stmt->arg_types[i] == T_DIR &&
			opcode_table[carry->stmt->statement - 1].dir_size == 4) 		// increment position
			step = 4;
		else
			step = 2;			// increment position
		pos = real_modulo(pos, step, MEM_SIZE);
		i++;
	}
	return (0);
}
