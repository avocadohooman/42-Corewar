/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x15_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:16 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 15:31:46 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_lfork(t_carriage *carriage, t_vm *vm)
{
	int               arg_value_1;
    unsigned char     *position;

    arg_value_1 = carriage->stmt->args[0];
    position = carriage->statement_pos[arg_value_1];
    copy_carriage(vm, carriage, position);
    vm->carry_nbr += 1;
}
