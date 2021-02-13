/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x15_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:16 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 16:53:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lfork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
	unsigned char     *position;

	arg_value_1 = carriage->stmt->args[0];
	position = &arena[(carriage->abs_pos + arg_value_1) % MEM_SIZE];
	copy_carriage(vm, carriage, position);
	vm->carriages->abs_pos = carriage->abs_pos + arg_value_1;
	vm->carry_nbr += 1;
}
