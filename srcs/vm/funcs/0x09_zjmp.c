/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/11 18:04:52 by gmolin           ###   ########.fr       */
=======
/*   Updated: 2021/02/11 21:54:47 by seronen          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	short           arg_idx_value;

	if (carriage->carry_flag)
	{
		arg_idx_value = carriage->stmt->args[0] % IDX_MOD;
		carriage->pos = &arena[carriage->abs_pos + arg_idx_value];
		carriage->abs_pos = carriage->abs_pos + arg_idx_value - 3;
	}
}
