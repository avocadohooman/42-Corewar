/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x10_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 19:29:57 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ldi(t_carriage *carriage, unsigned char *arena)
{
	int         arg_value_1;
	int         arg_value_2;
	int         args_idx_value;
	int         reg_slot;

	reg_slot = carriage->stmt->args[2] - 1;
	arg_value_1 = get_arg_value(carriage, 0, arena);
	arg_value_2 = get_arg_value(carriage, 1, arena);
    // if (carriage->stmt->arg_types[0] == T_IND)
    // {
    //     arg_value_2 = real_modulo(carriage->abs_pos, arg_value_2, IDX_MOD);
    //     args_idx_value = arg_value_1 + arg_value_2;
    // }
    // else 
    args_idx_value = real_modulo(carriage->abs_pos, (arg_value_1 + arg_value_2), IDX_MOD);
	carriage->regs[reg_slot] = read_bytes(arena, args_idx_value, 4);
}
