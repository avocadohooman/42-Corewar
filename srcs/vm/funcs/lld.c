/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:22 by seronen           #+#    #+#             */
/*   Updated: 2021/04/09 19:12:53 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_lld(t_carriage *carriage, unsigned char *arena, int opt)
{
	int			reg_slot;
	short		arg_idx_value;

	reg_slot = carriage->stmt->args[1] - 1;
	if (carriage->stmt->arg_types[0] == T_DIR)
		carriage->regs[reg_slot] = carriage->stmt->args[0];
	else if (carriage->stmt->arg_types[0] == T_IND)
	{
		arg_idx_value = real_modulo(carriage->abs_pos,
			carriage->stmt->args[0], MEM_SIZE);
		carriage->regs[reg_slot] = (short)read_bytes(arena, arg_idx_value, 2);
		if (opt)
			carriage->regs[reg_slot] =
				(short)read_bytes(arena, arg_idx_value, 4);
	}
	if (carriage->regs[reg_slot] == 0)
		carriage->carry_flag = 1;
	else
		carriage->carry_flag = 0;
}
