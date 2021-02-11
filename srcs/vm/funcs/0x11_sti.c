/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x11_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by seronen           #+#    #+#             */
/*   Updated: 2021/02/11 18:05:20 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_sti(t_carriage *carriage, unsigned char *arena)
{
	int         arg_value_1;
	int         arg_value_2;
	int         arg_value_3;
	int         args_idx_value;
	int         reg_slot;

	reg_slot = carriage->stmt->args[0] - 1;
	arg_value_1 = carriage->regs[reg_slot];
	arg_value_2 = get_arg_value(carriage, 1, arena);
	arg_value_3 = get_arg_value(carriage, 2, arena);
	args_idx_value = (arg_value_2 + arg_value_3);
	write_bytes(arena, real_modulo((carriage->abs_pos + args_idx_value), IDX_MOD), arg_value_1, 4);
}
