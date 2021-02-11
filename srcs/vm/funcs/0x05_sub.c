/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x05_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:14 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/11 17:41:46 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_sub(t_carriage *carriage)
{
	int     sum;
    int     reg_slot_1;
    int     reg_slot_2;
    int     reg_slot_3;

    reg_slot_1 = carriage->stmt->args[0] - 1;
    reg_slot_2 = carriage->stmt->args[1] - 1;
    reg_slot_3 = carriage->stmt->args[2] - 1;
	sum = carriage->regs[reg_slot_1];
	sum -= carriage->regs[reg_slot_2];
	carriage->regs[reg_slot_3] = sum;
	if (sum == 0)
		carriage->carry_flag = 1;
	else 
		carriage->carry_flag = 0;
}