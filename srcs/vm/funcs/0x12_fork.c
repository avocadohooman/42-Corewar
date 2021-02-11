/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:25 by seronen           #+#    #+#             */
/*   Updated: 2021/02/11 17:28:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_fork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
	unsigned char     *position;

	arg_value_1 = carriage->stmt->args[0];
	position = fetch_position(arena, (carriage->abs_pos + arg_value_1), IDX_MOD);
	copy_carriage(vm, carriage, position);
	vm->carriages->abs_pos = real_modulo((carriage->abs_pos + arg_value_1), IDX_MOD);
	vm->carry_nbr += 1;
}
