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

#include "libft.h"
#include "vm.h"
#include <stdio.h>

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

void		error(char *msg)
{
	printf("%s", msg);
	exit(0);
}

void		new_player(t_vm *vm, int id, char *name)
{
	t_player *new;

	new = malloc(sizeof(t_player));
	new->file_name = name;
	new->id = id;
	vm->players[id - 1] = new;
}

int		add_first(t_vm *vm, int player, char **args, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (args[i] && !ft_strcmp(args[i], "-n"))
			i += 2;
		else if (args[i])
		{
			new_player(vm ,player, ft_strdup(args[i]));
			args[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

int     arguments(t_vm *vm, int player, char **args, int ac)
{
	int i;
	int pos;

	i = 0;
	while (i++ < ac)
	{
		if (args[i] && !ft_strcmp(args[i], "-n"))
		{
			pos = ft_atoi(args[i + 1]);
			if (pos > MAX_PLAYERS)
				error("Poitional argument over limit!\n");
			if (pos == player)
			{
				new_player(vm ,player, ft_strdup(args[i + 2]));
				bzero(&args[i], sizeof(char*) * 3);
				return (0);
			}
			else
				i += 2;
		}
	}
	return (add_first(vm, player, args, ac));
}

int		get_positions(t_vm *vm, char **args, int ac)
{
	int player;

	player = 0;
	while (player < MAX_PLAYERS)
	{
		arguments(vm, player + 1, args, ac);
		player++;
	}
	return (0);
}

int     main(int ac, char **av)
{
	t_vm *vm;

	vm = malloc(sizeof(t_vm));
	vm->cur_id = 1;
	bzero(vm->players, sizeof(t_player) * MAX_PLAYERS + 1);
	get_positions(vm, av, ac);
	printf("\nPLAYER POSITIONS\n");
	if (vm->players[0])
		printf("\n1: Name: %s, id: %d\n", vm->players[0]->file_name, vm->players[0]->id);
	if (vm->players[1])
		printf("2: Name: %s, id: %d\n", vm->players[1]->file_name, vm->players[1]->id);
	if (vm->players[2])
		printf("3: Name: %s, id: %d\n", vm->players[2]->file_name, vm->players[2]->id);
	if (vm->players[3])
		printf("4: Name: %s, id: %d\n", vm->players[3]->file_name, vm->players[3]->id);
	return (0);
}