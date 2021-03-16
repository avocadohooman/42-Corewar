/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:08:10 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 17:51:25 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

int		read_arg(unsigned char *mem, int type, int pos, unsigned char stmt)
{
	if (type == T_REG)
		return ((int)mem[pos]);
	else if (type == T_DIR && opcode_table[stmt - 1].dir_size == 4)
		return (read_bytes(mem, pos, 4));
	else
		return ((short)read_bytes(mem, pos, 2));
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
		if (!carry->stmt->arg_types[i])
			break ;
		carry->stmt->args[i] = read_arg(arena, carry->stmt->arg_types[i], pos,
			carry->stmt->statement);
		if (carry->stmt->arg_types[i] == T_REG)
			step = 1;
		else if (carry->stmt->arg_types[i] == T_DIR &&
			opcode_table[carry->stmt->statement - 1].dir_size == 4)
			step = 4;
		else
			step = 2;
		pos = real_modulo(pos, step, MEM_SIZE);
		i++;
	}
	return (0);
}
