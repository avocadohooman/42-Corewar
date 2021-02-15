/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:54:48 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 15:36:06 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
	#include "buffer.h"
	t_buffer b;

	printf("hello vm\n");
	if (!new_buffer(&b, 10))
		return (1);

	for (int i = 0; i < 20; i++)
	{
		if (!insert_buffer(&b, "asd ", 4))
			return (1);
	}

	printf("%s\n", b.data);
	printf("%zu\n", b.size);
	printf("%zu\n", b.used);

	// t_test  a;
	// t_test  c;

	// a.value = 123;
	// c.value = 321;

	// llist_add((t_llist *)a, (t_llist *)c);

*/

void	announce_winner(t_vm *vm)
{
	if (vm->last_live)
	{
		ft_putstr("Player ");
		ft_putnbr(vm->last_live->id);
		ft_putstr(" (");
		ft_putstr(vm->last_live->name);
		ft_putendl(") won");
	}
}

void	dump_arena(unsigned char *arena)
{
	int i;
	int line;

	i = 0;
	while (i < MEM_SIZE)
	{
		line = 0;
		while (line < 64)
		{
			printf("%02x ", arena[i + line]);
			line++;
		}
		printf("\n");
		i += line;
	}
}

void	introduce_players(t_vm *vm)
{
	printf("\nIntroducing contestants...\n");
	if (vm->players[0])
		printf("* Player 1, weighing %d bytes, \"%s\" (\"%s\")!\n", vm->players[0]->exec_size, vm->players[0]->name, vm->players[0]->comment);
	if (vm->players[1])
		printf("* Player 2, weighing %d bytes, \"%s\" (\"%s\")!\n", vm->players[1]->exec_size, vm->players[1]->name, vm->players[1]->comment);
	if (vm->players[2])
		printf("* Player 3, weighing %d bytes, \"%s\" (\"%s\")!\n", vm->players[2]->exec_size, vm->players[2]->name, vm->players[2]->comment);
	if (vm->players[3])
		printf("* Player 4, weighing %d bytes, \"%s\" (\"%s\")!\n", vm->players[3]->exec_size, vm->players[3]->name, vm->players[3]->comment);
	printf("\n");
}

int     main(int ac, char **av)
{
	t_vm *vm;
	unsigned char *arena;

	vm = ft_memalloc(sizeof(t_vm));
	vm->dump = 0;
	vm->carry_nbr = 0;
	bzero(vm->players, sizeof(t_player *) * MAX_PLAYERS + 1);
	get_players(vm, av, ac);
	read_files(vm);
	introduce_players(vm);
	arena = init_arena(vm);
	battle_loop(vm, arena);
	announce_winner(vm);
	return (0);
}
