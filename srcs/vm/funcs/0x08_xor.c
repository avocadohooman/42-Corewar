/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x08_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:21 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/08 18:04:24 by orantane         ###   ########.fr       */
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