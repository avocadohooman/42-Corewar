/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:52:50 by seronen           #+#    #+#             */
/*   Updated: 2021/04/20 10:37:10 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				dump_arena(t_vm *vm, unsigned char *arena)
{
	int i;
	int line;
	int octets;

	i = 0;
	octets = 64;
	// if (vm->options[PRETTYDUMP])
	// 	octets = 64;
	vm->options[PRETTYDUMP] = 1;
	while (i < MEM_SIZE)
	{
		line = 0;
		// if (vm->options[PRETTYDUMP])
		// 	ft_printf("%#05x : ", i);
		while (line < octets)
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
