/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x01_live.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:34 by seronen           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 18:04:09 by orantane         ###   ########.fr       */
=======
/*   Updated: 2021/02/09 00:14:36 by seronen          ###   ########.fr       */
>>>>>>> master
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