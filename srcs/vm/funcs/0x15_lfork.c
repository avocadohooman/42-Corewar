/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x15_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:16 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 15:36:21 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lfork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
    unsigned char     *position;

    arg_value_1 = carriage->stmt->args[0];
    position = fetch_position(arena, carriage, arg_value_1 % MEM_SIZE);
    copy_carriage(vm, carriage, position);
    vm->carry_nbr += 1;
}
