/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 11:31:48 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage)
{
    short           arg_idx_value;
    int             offset;

    offset = 3;
	if (carriage->carry_flag)
    {
        arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
        if (arg_idx_value >= 0) 
            arg_idx_value -= offset;
        else
            arg_idx_value += offset;
        carriage->pos = &carriage->pos[arg_idx_value];
    }
}
