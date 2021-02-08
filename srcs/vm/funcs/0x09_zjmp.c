/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 18:04:26 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage)
{
	short           arg_idx_value;

	if (carriage->carry_flag)
	{
		arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
//      arg_idx_value = apply_offset(carriage, arg_idx_value);
		carriage->pos = &carriage->statement_pos[arg_idx_value];
	}
}
