/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:52:50 by seronen           #+#    #+#             */
/*   Updated: 2021/02/05 15:41:06 by Gerhard          ###   ########.fr       */
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
		if ((a_index + vm->players[player]->exec_size) > MEM_SIZE)
			print_error(MALLOC);
		ft_memcpy(&arena[a_index], &vm->players[player]->exec_code, vm->players[player]->exec_size);
		a_index += MEM_SIZE / vm->player_nb;
		player++;
	}
	return (0);
}

unsigned char		*init_arena(t_vm *vm)
{
	unsigned char *arena;

	if (!(arena = malloc(sizeof(unsigned char) * MEM_SIZE)))
		print_error(MALLOC);
	place_players(vm, arena);
	initiate_carriages(vm, arena);
	return (arena);
}
