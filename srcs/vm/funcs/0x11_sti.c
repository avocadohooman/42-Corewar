/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x11_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:27 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 18:04:30 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_sti(t_carriage *carriage)
{
	int         arg_value_1;
	int         arg_value_2;
	int         arg_value_3;
	int         args_idx_value;
	int         reg_slot;

	reg_slot = carriage->stmt->args[2] - 1;
	arg_value_1 = carriage->regs[reg_slot];
	arg_value_2 = get_arg_value(carriage, arg_value_2, 1);
	arg_value_3 = get_arg_value(carriage, arg_value_3, 2);
	args_idx_value = (arg_value_1 + arg_value_2) % IDX_MOD;
//	args_idx_value = apply_offset(carriage, args_idx_value);
	write_bytes(&carriage->statement_pos[args_idx_value], arg_value_1, 4);
}