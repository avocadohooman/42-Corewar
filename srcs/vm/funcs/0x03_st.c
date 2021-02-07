/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/07 10:36:50 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_st(t_carriage *carriage)
{
    int     arg_value;
    int     arg_idx_value;
    int     reg_slot_1;
    int     reg_slot_2;

    reg_slot_1 = carriage->stmt->args[0] - 1;
    reg_slot_2 = carriage->stmt->args[1] - 1;
    arg_value = carriage->regs[reg_slot_1];
    arg_idx_value = (short)arg_value % IDX_MOD;
    if (carriage->stmt->arg_types[1] == 1)
        carriage->regs[reg_slot_2] = arg_value;
    else if (carriage->stmt->arg_types[1] == 4)
        carriage->regs[reg_slot_2] = arg_idx_value;
}