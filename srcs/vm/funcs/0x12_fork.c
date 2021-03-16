/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:25 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 13:58:26 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_fork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;

    arg_value_1 = real_modulo(carriage->abs_pos, carriage->stmt->args[0], IDX_MOD);
	copy_carriage(vm, carriage);
	vm->carriages->abs_pos = arg_value_1 % MEM_SIZE;
	vm->carry_nbr += 1;
}
