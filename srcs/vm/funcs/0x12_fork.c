/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:25 by seronen           #+#    #+#             */
/*   Updated: 2021/02/11 21:56:39 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_fork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
	unsigned char     *position;

	arg_value_1 = carriage->stmt->args[0] % IDX_MOD;
	position = &arena[carriage->abs_pos + arg_value_1];
	copy_carriage(vm, carriage, position);
	vm->carriages->abs_pos = carriage->abs_pos + arg_value_1;
	vm->carry_nbr += 1;
}
