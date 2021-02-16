/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x01_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:34 by seronen           #+#    #+#             */
/*   Updated: 2021/02/16 15:05:47 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_live(t_carriage *carriage, t_vm *vm)
{
	int player_id;

	player_id = carriage->stmt->args[0] * -1;
	carriage->last_live = carriage->cycle;
	if (player_id <= vm->player_nb && player_id > 0)
		vm->last_live = vm->players[player_id - 1];
}