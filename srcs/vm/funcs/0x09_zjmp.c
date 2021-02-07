/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 12:29:01 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage)
{
    short           arg_idx_value;

	if (carriage->carry_flag)
    {
        arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
        arg_idx_value = apply_offset(carriage, arg_idx_value);
        carriage->pos = &carriage->pos[arg_idx_value];
    }
}
