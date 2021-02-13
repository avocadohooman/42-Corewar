/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:50:25 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/13 19:07:06 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int      get_arg_value(t_carriage *carriage, int i, unsigned char *arena)
{
    int         reg_slot;
    int         arg_value;
    short       arg_idx_value;

    if (carriage->stmt->arg_types[i] == T_REG)
    {
        reg_slot = carriage->stmt->args[i] - 1;
        arg_value = carriage->regs[reg_slot];
    } 
    else if (carriage->stmt->arg_types[i] == T_DIR)
        arg_value = carriage->stmt->args[i];
    else 
    {
        // arg_idx_value = (short)carriage->stmt->args[i] % IDX_MOD;
        arg_idx_value = real_modulo(carriage->abs_pos, (short)carriage->stmt->args[i], IDX_MOD);
        arg_value = (short)read_bytes(arena, arg_idx_value, 4);
    }
    return (arg_value);
}
