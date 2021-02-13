/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x11_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 19:14:28 by gmolin           ###   ########.fr       */
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
    if (carriage->stmt->arg_types[1] == T_IND)
    {
        arg_value_3 = real_modulo(carriage->abs_pos, arg_value_3, IDX_MOD);
        args_idx_value = arg_value_3 + arg_value_2;
    }
    else 
	    args_idx_value = real_modulo(carriage->abs_pos, (arg_value_2 + arg_value_3), IDX_MOD);
	write_bytes(arena, args_idx_value, arg_value_1, 4);
}
