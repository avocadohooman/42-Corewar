/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x02_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 12:22:13 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_ld(t_carriage *carriage)
{
    int     reg_slot;
    int     arg_idx_value;

    reg_slot = carriage->stmt->args[1] - 1;
    if (carriage->stmt->arg_types[0] == 2)
        carriage->regs[reg_slot] = carriage->stmt->args[0];
    else if (carriage->stmt->arg_types[0] == 4)
    {
        arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
        arg_idx_value = apply_offset(carriage, arg_idx_value);
        carriage->regs[reg_slot] = convert_4_bytes(&carriage->pos[arg_idx_value]);
    }
    if (carriage->stmt->args[0] == 0)
        carriage->carry_flag = 1;
    else 
        carriage->carry_flag = 0;
}
