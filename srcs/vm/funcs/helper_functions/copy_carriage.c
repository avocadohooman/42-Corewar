/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:11:47 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/10 13:26:49 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void        copy_carriage(t_vm *vm, t_carriage *current, unsigned char *pos)
{
    int     reg_slot;

    reg_slot = 0;
    vm->carriages = create_carriage(vm, vm->carriages, current->regs[0], pos);
    vm->carriages->carry_flag = current->carry_flag;
    vm->carriages->last_live = current->last_live;
    vm->carriages->cycle = current->cycle;
    while (reg_slot < REG_NUMBER)
    {
        vm->carriages->regs[reg_slot] = current->regs[reg_slot];
        reg_slot++;
    }
}
