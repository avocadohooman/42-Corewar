/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x14_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:19 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 14:34:57 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lldi(t_carriage *carriage)
{
	int         arg_value_1;
    int         arg_value_2;
    int         args_idx_value;
    int         reg_slot;

    reg_slot = carriage->stmt->args[2] - 1;
    arg_value_1 = get_arg_value(carriage, arg_value_1, 0);
    arg_value_2 = get_arg_value(carriage, arg_value_2, 1);
    args_idx_value = (arg_value_1 + arg_value_2) % MEM_SIZE;
    args_idx_value = apply_offset(carriage, args_idx_value);
    carriage->regs[reg_slot] = convert_4_bytes(&carriage->pos[args_idx_value]);
}
