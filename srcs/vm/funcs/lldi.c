/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:19 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 18:14:23 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_lldi(t_carriage *carriage, unsigned char *arena)
{
	int		arg_value_1;
	int		arg_value_2;
	int		args_idx_value;
	int		reg_slot;

	reg_slot = carriage->stmt->args[2] - 1;
	arg_value_1 = get_arg_value(carriage, 0, arena);
	arg_value_2 = get_arg_value(carriage, 1, arena);
	args_idx_value = real_modulo(carriage->abs_pos,
		(arg_value_1 + arg_value_2), MEM_SIZE);
	carriage->regs[reg_slot] = read_bytes(arena, args_idx_value, 4);
	if (carriage->regs[reg_slot] == 0)
		carriage->carry_flag = 1;
	else
		carriage->carry_flag = 0;
}
