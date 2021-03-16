/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 13:58:19 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int am;

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	int           arg_idx_value;

	if (!am)
		am = 0;
	if (carriage->carry_flag)
	{
		am++;
		int old = carriage->abs_pos;
        arg_idx_value = real_modulo(carriage->abs_pos, carriage->stmt->args[0], IDX_MOD);
		carriage->abs_pos = arg_idx_value;
		carriage->abs_pos = real_modulo(carriage->abs_pos, -3, MEM_SIZE);
	}
}
