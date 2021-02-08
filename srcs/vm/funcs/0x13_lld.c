/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x13_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:22 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 14:33:57 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lld(t_carriage *carriage)
{
    int     reg_slot;
    int     arg_value;

    reg_slot = carriage->stmt->args[1] - 1;
    arg_value = (short)carriage->stmt->args[0] % MEM_SIZE;
    if (carriage->stmt->arg_types[0] == 2)
        carriage->regs[reg_slot] = carriage->stmt->args[0];
    else if (carriage->stmt->arg_types[0] == 4)
        carriage->regs[reg_slot] = convert_4_bytes(&carriage->pos[arg_value]);
    if (carriage->stmt->args[0] == 0)
        carriage->carry_flag = 1;
    else 
        carriage->carry_flag = 0;
}