/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:08:10 by seronen           #+#    #+#             */
/*   Updated: 2021/02/15 22:24:55 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

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
	if (opcode_table[carry->stmt->statement - 1].argument_type)
		pos++;
	while (i < 3)
	{
		if (!carry->stmt->arg_types[i])		// Dont read if no arg, no arg type so no arg...
			break ;
		carry->stmt->args[i] = read_arg(carry->pos,carry->stmt->arg_types[i], pos, carry->stmt->statement);
		if ((carry->stmt->arg_types[i] == T_DIR && opcode_table[carry->stmt->statement - 1].dir_size == 2) || carry->stmt->arg_types[i] == T_IND)
			carry->stmt->args[i] = (short)read_arg(carry->pos, carry->stmt->arg_types[i], pos, carry->stmt->statement);
		if (carry->stmt->arg_types[i] == T_REG)		// increment position
			pos += 1;
		else if (carry->stmt->arg_types[i] == T_DIR &&
			opcode_table[carry->stmt->statement - 1].dir_size == 4) 		// increment position
			pos += 4;
		else
			pos += 2;			// increment position
		i++;
	}
	return (0);
}

