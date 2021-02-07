/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:50:25 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/07 12:40:48 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int      get_arg_value(t_carriage *carriage, int arg_value, int i)
{
    int     reg_slot;
    int     arg_idx_value;

    if (carriage->stmt->arg_type[i] == 1)
    {
        reg_slot = carriage->stmt->args[i] - 1;
        arg_value = carriage->regs[reg_slot];
    } 
    else if (carriage->stmt-arg_type[i] == 2) 
        arg_value = carriage->stmt->args[i];
    else 
    {
        arg_idx_value = (short)carriage->stmt->args[i] % IDX_MOD;
        arg_idx_value = apply_offset(carriage, arg_idx_value);
        arg_value = convert_4_bytes(&carriage->pos[arg_idx_value]);
    }
    return (arg_value);
}
