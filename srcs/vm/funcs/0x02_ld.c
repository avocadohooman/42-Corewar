/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x02_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/15 19:33:03 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ld(t_carriage *carriage, unsigned char *arena)
{
	int         reg_slot;
	int      	arg_idx_value;

	reg_slot = carriage->stmt->args[1] - 1;
	if (carriage->stmt->arg_types[0] == T_DIR)
		carriage->regs[reg_slot] = carriage->stmt->args[0];
	else if (carriage->stmt->arg_types[0] == T_IND)
	{
		// arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
        arg_idx_value = real_modulo(carriage->abs_pos, (short)carriage->stmt->args[0], IDX_MOD);
		carriage->regs[reg_slot] = read_bytes(arena, arg_idx_value, 4);
	}
	if (carriage->regs[reg_slot] == 0)
		carriage->carry_flag = 1;
	else 
		carriage->carry_flag = 0;
}
