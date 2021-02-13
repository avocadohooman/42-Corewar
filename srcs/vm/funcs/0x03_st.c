/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/11 18:06:16 by gmolin           ###   ########.fr       */
=======
/*   Updated: 2021/02/11 21:53:11 by seronen          ###   ########.fr       */
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
<<<<<<< HEAD
		arg_idx_value = arg_2;
		write_bytes(arena, real_modulo((carriage->abs_pos + arg_idx_value), IDX_MOD), arg_value, 4);
=======
		arg_idx_value = arg_2 % IDX_MOD;
		write_bytes(arena, carriage->abs_pos + arg_idx_value, arg_value, 4);
>>>>>>> master
	}
}
