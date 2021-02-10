/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x12_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:25 by seronen           #+#    #+#             */
/*   Updated: 2021/02/10 15:18:24 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_fork(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	int               arg_value_1;
    unsigned char     *position;

    // printf("FORK player: %d", carriage->regs[0]);
    arg_value_1 = carriage->stmt->args[0];
    position = fetch_position(arena, carriage, arg_value_1 % IDX_MOD);
    copy_carriage(vm, carriage, position);
    vm->carriages->abs_pos -= 3;
    vm->carry_nbr += 1;
}
