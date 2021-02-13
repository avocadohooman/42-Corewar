/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/13 18:53:15 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	int           arg_idx_value;

	if (carriage->carry_flag)
	{
		// arg_idx_value = carriage->stmt->args[0] % IDX_MOD;
        arg_idx_value = real_modulo(carriage->abs_pos, (short)carriage->stmt->args[0], IDX_MOD);
		carriage->pos = &arena[arg_idx_value];
		carriage->abs_pos = carriage->abs_pos + arg_idx_value - 3;
	}
}
