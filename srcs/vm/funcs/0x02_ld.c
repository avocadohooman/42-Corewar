/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x02_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 14:27:38 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ld(t_carriage *carriage)
{
    int     reg_slot;
    int     arg_value_idx;

    reg_slot = carriage->stmt->args[1] - 1;
    arg_value_idx = (short)carriage->stmt->args[0] % IDX_MOD;
    if (carriage->stmt->arg_types[0] == 2)
        carriage->regs[reg_slot] = carriage->stmt->args[0];
    else if (carriage->stmt->arg_types[0] == 4)
        carriage->regs[reg_slot] = convert_4_bytes(&carriage->pos[arg_value_idx]);
    if (carriage->stmt->args[0] == 0)
        carriage->carry_flag = 1;
    else 
        carriage->carry_flag = 0;
}

