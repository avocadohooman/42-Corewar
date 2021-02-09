/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:04:19 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/08 23:29:15 by seronen          ###   ########.fr       */
>>>>>>> master
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
		arg_idx_value = (short)arg_2 % IDX_MOD;
		write_bytes(arena, (carriage->abs_pos + arg_idx_value) % IDX_MOD, arg_value, 4);
	}
}
