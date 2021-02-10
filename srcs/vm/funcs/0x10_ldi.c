/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x10_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/10 19:01:02 by seronen          ###   ########.fr       */
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
	args_idx_value = (arg_value_1 + arg_value_2);
	carriage->regs[reg_slot] = read_bytes(arena, real_modulo((carriage->abs_pos + args_idx_value), IDX_MOD), 4);
}
