/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:46:02 by seronen           #+#    #+#             */
/*   Updated: 2021/04/09 19:40:20 by seronen          ###   ########.fr       */
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
	ft_putendl("Introducing contestants...");
	while (++i < vm->player_nb)
	{
		if (vm->players[i])
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
	}
	ft_putchar('\n');
}

t_vm	*init_game(void)
{
	t_vm *vm;

	vm = ft_memalloc(sizeof(t_vm));
	if (!vm)
		print_error(MALLOC);
	vm->carry_nbr = 0;
	ft_bzero(vm->players, sizeof(t_player *) * MAX_PLAYERS);
	ft_bzero(vm->options, sizeof(int) * OPT_AMOUNT);
	return (vm);
}

int		main(int ac, char **av)
{
	t_vm			*vm;
	unsigned char	*arena;

	vm = init_game();
	parse_args(vm, &av[1], ac - 1);
	read_files(vm);
	introduce_players(vm);
	if (!(arena = init_arena(vm)))
		print_error(MALLOC);
	battle_loop(vm, arena);
	announce_winner(vm);
	return (EXIT_SUCCESS);
}
