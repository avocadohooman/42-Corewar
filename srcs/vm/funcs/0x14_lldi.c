/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x14_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:19 by seronen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:07:07 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/08 23:42:41 by seronen          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lldi(t_carriage *carriage, unsigned char *arena)
{
	int         arg_value_1;
	int         arg_value_2;
	int         args_idx_value;
	int         reg_slot;

	reg_slot = carriage->stmt->args[2] - 1;
	arg_value_1 = get_arg_value(carriage, 0, arena);
	arg_value_2 = get_arg_value(carriage, 1, arena);
	args_idx_value = (arg_value_1 + arg_value_2) % MEM_SIZE;
<<<<<<< HEAD
//	args_idx_value = apply_offset(carriage, args_idx_value);
	carriage->regs[reg_slot] = convert_4_bytes(&carriage->statement_pos[args_idx_value]);
}
=======
	carriage->regs[reg_slot] = read_bytes(arena, carriage->abs_pos + args_idx_value, 4);
}
>>>>>>> master
