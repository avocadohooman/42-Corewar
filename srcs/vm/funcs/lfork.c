/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:16 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 18:13:09 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lfork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int			arg_value_1;
	int			arg_idx_value;

	arg_value_1 = carriage->stmt->args[0];
	arg_idx_value = real_modulo(carriage->abs_pos, arg_value_1, MEM_SIZE);
	copy_carriage(vm, carriage);
	vm->carriages->abs_pos = arg_idx_value % MEM_SIZE;
	vm->carry_nbr += 1;
}
