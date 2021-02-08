/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x02_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 23:31:13 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ld(t_carriage *carriage, unsigned char *arena)
{
	int     reg_slot;
	int     arg_idx_value;

	reg_slot = carriage->stmt->args[1] - 1;
	if (carriage->stmt->arg_types[0] == T_DIR)
		carriage->regs[reg_slot] = carriage->stmt->args[0];
	else if (carriage->stmt->arg_types[0] == T_IND)
	{
		arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
		carriage->regs[reg_slot] = read_bytes(arena, (carriage->abs_pos + arg_idx_value) % IDX_MOD, 4);
	}
	if (carriage->regs[reg_slot] == 0)
		carriage->carry_flag = 1;
	else 
		carriage->carry_flag = 0;
}
