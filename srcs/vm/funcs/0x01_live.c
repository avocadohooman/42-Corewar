/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x01_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:34 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 00:14:36 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_live(t_carriage *carriage, t_vm *vm)
{
	int player_id;

	player_id = carriage->stmt->args[0] * -1;
	if (player_id <= vm->player_nb && player_id > 0)
	{
		carriage->last_live = carriage->cycle;
		printf("Player %d '%s' is alive\n", player_id, vm->players[player_id - 1]->name);
	}
}
