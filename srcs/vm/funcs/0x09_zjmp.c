/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/16 20:11:42 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	int           arg_idx_value;

	if (carriage->carry_flag)
	{
		// arg_idx_value = carriage->stmt->args[0] % IDX_MOD;
        arg_idx_value = real_modulo(carriage->abs_pos, carriage->stmt->args[0], IDX_MOD);
		carriage->abs_pos = arg_idx_value - 3;
	}
}
