/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:52:50 by seronen           #+#    #+#             */
/*   Updated: 2021/04/10 13:38:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				dump_arena(unsigned char *arena)
{
	int i;
	int line;

	i = 0;
	while (i < MEM_SIZE)
	{
		line = 0;
		ft_printf("%#05x : ", i);
		while (line < 64)
		{
			ft_printf("%02x ", arena[i + line]);
			line++;
		}
		ft_printf("\n");
		i += line;
	}
}

int					place_players(t_vm *vm, unsigned char *arena)
{
	int player;
	int a_index;

	player = 0;
	a_index = 0;
	while (player < vm->player_nb)
	{
		if ((a_index + vm->players[player]->exec_size) > MEM_SIZE)
			print_error(MALLOC);
		ft_memcpy(&arena[a_index], vm->players[player]->exec_code,
			vm->players[player]->exec_size);
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
	initiate_carriages(vm);
	return (arena);
}
