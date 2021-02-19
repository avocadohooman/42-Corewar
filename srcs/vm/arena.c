/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:52:50 by seronen           #+#    #+#             */
/*   Updated: 2021/02/19 16:47:00 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			place_players(t_vm *vm, unsigned char *arena)
{
	int player;
	int a_index;
	
	player = 0;
	a_index = 0;
	while (player < vm->player_nb)
	{
		printf("a_index: %d, player: %d\n", a_index, player);
		if ((a_index + vm->players[player]->exec_size) > MEM_SIZE)
			print_error(MALLOC);
		ft_memcpy(&arena[a_index], vm->players[player]->exec_code, vm->players[player]->exec_size);
		a_index += MEM_SIZE / vm->player_nb;
		player++;
	}
	return (0);
}

unsigned char		*init_arena(t_vm *vm)
{
	unsigned char *arena;

	if (!(arena = ft_memalloc(sizeof(char) * MEM_SIZE)))
		print_error(MALLOC);
	place_players(vm, arena);
	initiate_carriages(vm, arena);
	return (arena);
}
