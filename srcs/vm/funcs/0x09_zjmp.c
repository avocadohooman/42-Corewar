/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/11 18:04:52 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage, unsigned char *arena)
{
	short           arg_idx_value;

	if (carriage->carry_flag)
	{
		arg_idx_value = carriage->stmt->args[0];
		carriage->pos = fetch_position(arena, (carriage->abs_pos + arg_idx_value), IDX_MOD);
		carriage->abs_pos += arg_idx_value - 3;
	}
}
