/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 01:36:44 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	short           arg_idx_value;

	if (carriage->carry_flag)
	{
		arg_idx_value = (short)carriage->stmt->args[0] % IDX_MOD;
		carriage->pos = fetch_position(arena, carriage, arg_idx_value);
		carriage->abs_pos += arg_idx_value - 3;
	}
}
