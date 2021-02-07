/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x10_ldi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 12:53:14 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ldi(t_carriage *carriage)
{
	int         arg_value_1;
    int         arg_value_2;
    int         args_idx_value;
    int         reg_slot;

    reg_slot = carriage->stmt->args[2] - 1;
    arg_value_1 = get_arg_value(carriage, arg_value_1, 0);
    arg_value_2 = get_arg_value(carriage, arg_value_2, 1);
    args_idx_value = (arg_value_1 + arg_value_2) % IDX_MOD;
    args_idx_value = apply_offset(carriage, args_idx_value);
    carriage->regs[reg_slot] = convert_4_bytes(&carriage->pos[args_idx_value]);
}
