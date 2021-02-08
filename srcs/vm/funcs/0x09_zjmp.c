/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 14:27:45 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage)
{
    int     arg_idx_value;

	if (carriage->carry_flag)
    {
        arg_idx_value = carriage->stmt->args[0] % IDX_MOD;
        printf("IDX VALIE: %d\n", carriage->stmt->args[0] % IDX_MOD);
    }
}
