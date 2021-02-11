/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/11 18:06:16 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_st(t_carriage *carriage, unsigned char *arena)
{
	int     arg_value;
	int     arg_idx_value;
	int     arg_1;
	int     arg_2;

	arg_1 = carriage->stmt->args[0] - 1;
	arg_value = carriage->regs[arg_1];
	arg_2 = carriage->stmt->args[1];
	if (carriage->stmt->arg_types[1] == T_REG)
		carriage->regs[arg_2 - 1] = arg_value;
	else if (carriage->stmt->arg_types[1] == T_IND)
	{
		arg_idx_value = arg_2;
		write_bytes(arena, real_modulo((carriage->abs_pos + arg_idx_value), IDX_MOD), arg_value, 4);
	}
}
