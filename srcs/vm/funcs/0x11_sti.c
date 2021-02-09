/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x11_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by seronen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:38:52 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/08 23:42:19 by seronen          ###   ########.fr       */
>>>>>>> master
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
<<<<<<< HEAD
	arg_value_2 = get_arg_value(carriage, arg_value_2, 1);
	arg_value_3 = get_arg_value(carriage, arg_value_3, 2);
	args_idx_value = (arg_value_2 + arg_value_3) % IDX_MOD;
//	args_idx_value = apply_offset(carriage, args_idx_value);
	write_bytes(&carriage->statement_pos[args_idx_value], arg_value_1, 4);
}
=======
	arg_value_2 = get_arg_value(carriage, 1, arena);
	arg_value_3 = get_arg_value(carriage, 2, arena);
	args_idx_value = (arg_value_2 + arg_value_3) % IDX_MOD;
	write_bytes(arena, carriage->abs_pos + args_idx_value, arg_value_1, 4);
}
>>>>>>> master
