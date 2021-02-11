/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:11:47 by Gerhard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/10 14:39:59 by Gerhard          ###   ########.fr       */
=======
/*   Updated: 2021/02/10 19:24:53 by orantane         ###   ########.fr       */
>>>>>>> master
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
    vm->carriages->id = vm->id_tracker;
    while (reg_slot < REG_NUMBER)
    {
        vm->carriages->regs[reg_slot] = current->regs[reg_slot];
        reg_slot++;
    }
}
