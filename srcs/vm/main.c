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

void	print_info(t_vm *vm)
{
	if (vm->dump)
		printf("Found dump with value: %d\n", vm->dump);
	printf("\nPLAYER POSITIONS\n");
	if (vm->players[0])
		printf("\n1: Name: %s, id: %d\n", vm->players[0]->file_name, vm->players[0]->id);
	if (vm->players[1])
		printf("2: Name: %s, id: %d\n", vm->players[1]->file_name, vm->players[1]->id);
	if (vm->players[2])
		printf("3: Name: %s, id: %d\n", vm->players[2]->file_name, vm->players[2]->id);
	if (vm->players[3])
		printf("4: Name: %s, id: %d\n", vm->players[3]->file_name, vm->players[3]->id);
}

int     main(int ac, char **av)
{
	t_vm *vm;

	vm = malloc(sizeof(t_vm));
	vm->dump = 0;
	bzero(vm->players, sizeof(t_player) * MAX_PLAYERS + 1);
	get_players(vm, av, ac);
	print_info(vm);
	read_files(vm);
	return (0);
}
