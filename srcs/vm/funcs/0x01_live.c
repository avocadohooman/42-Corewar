/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x01_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:34 by seronen           #+#    #+#             */
/*   Updated: 2021/02/10 15:20:36 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_live(t_carriage *carriage, t_vm *vm)
{
	int player_id;

	player_id = carriage->stmt->args[0] * -1;
	// printf("id %d, carry_nbr %d, cycle %d\n", player_id, vm->carry_nbr, carriage->cycle);
	if (player_id <= vm->player_nb && player_id > 0)
	{
		vm->last_live = vm->players[player_id - 1];
		carriage->last_live = carriage->cycle;
		printf("Player %d '%s' is alive\n", player_id, vm->players[player_id - 1]->name);
	}
}