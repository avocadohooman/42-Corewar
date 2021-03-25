/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:19 by Gerhard           #+#    #+#             */
/*   Updated: 2021/03/16 18:14:53 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_or(t_carriage *carriage, unsigned char *arena)
{
	int		arg_one_value;
	int		arg_two_value;
	int		reg_slot;

	reg_slot = carriage->stmt->args[2] - 1;
	arg_one_value = get_arg_value(carriage, 0, arena);
	arg_two_value = get_arg_value(carriage, 1, arena);
	carriage->regs[reg_slot] = arg_one_value | arg_two_value;
	carriage->carry_flag = !(arg_one_value | arg_two_value);
}
