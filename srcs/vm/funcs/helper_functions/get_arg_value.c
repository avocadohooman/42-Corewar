/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:50:25 by Gerhard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:04:47 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/08 23:39:44 by seronen          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int      get_arg_value(t_carriage *carriage, int i, unsigned char *arena)
{
    int     reg_slot;
    int     arg_value;
    int     arg_idx_value;

    if (carriage->stmt->arg_types[i] == T_REG)
    {
        reg_slot = carriage->stmt->args[i] - 1;
        arg_value = carriage->regs[reg_slot];
    } 
    else if (carriage->stmt->arg_types[i] == T_DIR)
        arg_value = carriage->stmt->args[i];
    else 
    {
        arg_idx_value = (short)carriage->stmt->args[i] % IDX_MOD;
        arg_value = read_bytes(arena, (carriage->abs_pos + arg_idx_value) % IDX_MOD, 4);
    }
    return (arg_value);
}
