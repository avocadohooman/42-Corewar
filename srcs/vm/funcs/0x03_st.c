/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/15 19:33:18 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_st(t_carriage *carriage, unsigned char *arena)
{
	int         arg_value;
	int      	arg_idx_value;
	int         arg_1;
	int         arg_2;

	arg_1 = carriage->stmt->args[0] - 1;
	arg_value = carriage->regs[arg_1];
	arg_2 = carriage->stmt->args[1];
	if (carriage->stmt->arg_types[1] == T_REG)
		carriage->regs[arg_2 - 1] = arg_value;
	else if (carriage->stmt->arg_types[1] == T_IND)
	{
		// arg_idx_value = (short)arg_2 % IDX_MOD;
        arg_idx_value = real_modulo(carriage->abs_pos, (short)arg_2, IDX_MOD);
        // printf("ST ARG IDX VALIE: %d %.2x\n", arg_idx_value, carriage->stmt->statement);
    	write_bytes(arena, arg_idx_value, arg_value, 4);
	}
}
