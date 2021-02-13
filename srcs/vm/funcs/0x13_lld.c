/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x13_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:22 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 19:02:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lld(t_carriage *carriage, unsigned char *arena)
{
	int         reg_slot;
	short       arg_idx_value;

	reg_slot = carriage->stmt->args[1] - 1;
	if (carriage->stmt->arg_types[0] == T_DIR)
		carriage->regs[reg_slot] = carriage->stmt->args[0];
	else if (carriage->stmt->arg_types[0] == T_IND)
	{
		// arg_idx_value = (short)carriage->stmt->args[0] % MEM_SIZE;
        arg_idx_value = real_modulo(carriage->abs_pos, (short)carriage->stmt->args[0], IDX_MOD);
		carriage->regs[reg_slot] = read_bytes(arena, arg_idx_value, 4);
	}
	if (carriage->stmt->args[0] == 0)
		carriage->carry_flag = 1;
	else 
		carriage->carry_flag = 0;
}
