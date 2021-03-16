/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:46:02 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 17:46:45 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	announce_winner(t_vm *vm)
{
	if (vm->last_live)
	{
		ft_putstr("Contestant ");
		ft_putnbr(vm->last_live->id);
		ft_putstr(", \"");
		ft_putstr(vm->last_live->name);
		ft_putendl("\" has won !");
	}
}

void	introduce_players(t_vm *vm)
{
	int i;

	i = -1;
	printf("Introducing contestants...\n");
	while (++i < vm->player_nb)
	{
		ft_putstr("* Player ");
		ft_putnbr(i + 1);
		ft_putstr(", weighing ");
		ft_putnbr(vm->players[i]->exec_size);
		ft_putstr(" bytes, \"");
		ft_putstr(vm->players[i]->name);
		ft_putstr("\" (\"");
		ft_putstr(vm->players[i]->comment);
		ft_putstr("\") !\n");
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	t_vm			*vm;
	unsigned char	*arena;

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
