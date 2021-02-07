/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x08_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:21 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/07 10:37:47 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_xor(t_carriage *carriage)
{
    int     arg_one_value;
    int     arg_two_value;
    int     reg_slot;

    reg_slot = carriage->stmt->args[2] - 1;
    arg_one_value = get_arg_value(carriage, arg_one_value, 0);
    arg_two_value = get_arg_value(carriage, arg_two_value, 1);
    carriage->regs[reg_slot] = arg_one_value ^ arg_two_value;
    carriage->carry_flag = !(arg_one_value ^ arg_two_value);
}