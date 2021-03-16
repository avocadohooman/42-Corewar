/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:46:01 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 17:38:18 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int			add_first(t_vm *vm, int player, char **args, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (args[i] && !ft_strcmp(args[i], "-n"))
			i += 2;
		if (args[i] && !ft_strcmp(args[i], "-dump"))
			i++;
		else if (args[i])
		{
			new_player(vm, player, ft_strdup(args[i]));
			args[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

int					validate_nb(char *str, int player)
{
	int i;
	int nb;

	i = 0;
	if (!str)
		print_error(MISSING_ARG);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(INVALID_ARG);
		i++;
	}
	nb = ft_atoi(str);
	if (!player)
		return (nb + 1);
	if (nb < 1)
		print_error(INVALID_ARG);
	if (player && (nb < player || nb > MAX_PLAYERS))
		print_error(INVALID_ARG);
	return (nb);
}

static int			arguments(t_vm *vm, int player, char **args, int ac)
{
	int i;
	int pos;

	i = 0;
	while (i++ < ac)
	{
		if (args[i] && (!ft_strcmp(args[i], "-n")))
		{
			pos = validate_nb(args[i + 1], player);
			if (pos == player)
			{
				new_player(vm, player, ft_strdup(args[i + 2]));
				bzero(&args[i], sizeof(char*) * 3);
				return (0);
			}
			else
				i += 2;
		}
	}
	return (add_first(vm, player, args, ac));
}

int					get_players(t_vm *vm, char **args, int ac)
{
	int player;

	player = 0;
	if (!args || ac < 2)
		print_error(INVALID_ARG);
	vm->player_nb = get_player_amount(vm, args, ac);
	if (vm->player_nb > MAX_PLAYERS || vm->player_nb < MIN_PLAYERS)
		print_error(INVALID_ARG);
	while (player < vm->player_nb)
	{
		arguments(vm, player + 1, args, ac);
		if (!vm->players[player])
			print_error(INVALID_ARG);
		player++;
	}
	return (0);
}
