/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:25 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 19:01:14 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_fork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
	unsigned char     *position;

	// arg_value_1 = carriage->stmt->args[0] % IDX_MOD;
    arg_value_1 = real_modulo(carriage->abs_pos, carriage->stmt->args[0], IDX_MOD);
	position = &arena[arg_value_1];
	copy_carriage(vm, carriage, position);
	vm->carriages->abs_pos = arg_value_1;
	vm->carry_nbr += 1;
}
