/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:19:33 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/09 01:36:44 by seronen          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	short           arg_idx_value;

	if (carriage->carry_flag)
	{
		arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
<<<<<<< HEAD
//      arg_idx_value = apply_offset(carriage, arg_idx_value);
		carriage->pos = &carriage->statement_pos[arg_idx_value];
		printf("Value %02x, arg_idx_value %d\n", carriage->pos[0], arg_idx_value);
=======
		carriage->pos = fetch_position(arena, carriage, arg_idx_value);
		carriage->abs_pos += arg_idx_value - 3;
>>>>>>> master
	}
}
