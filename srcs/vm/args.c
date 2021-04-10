/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:46:01 by seronen           #+#    #+#             */
/*   Updated: 2021/04/10 00:33:10 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int			add_first(t_vm *vm, int player, char **args, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (args[i] && !ft_strcmp(args[i], PLAYERNB_LITERAL))
			i += 2;
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
	if (!str || !player)
		print_error(MISSING_ARG);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(INVALID_ARG);
		i++;
	}
	nb = ft_atoi(str);
	if (nb < 1 || nb < player || nb > MAX_PLAYERS)
		print_error(INVALID_ARG);
	return (nb);
}

static int			arguments(t_vm *vm, int player, char **args, int ac)
{
	int i;
	int pos;

	i = 0;
	while (i < ac)
	{
		if (args[i] && (!ft_strcmp(args[i], PLAYERNB_LITERAL)))
		{
			pos = validate_nb(args[i + 1], player);
			if (pos == player)
			{
				new_player(vm, player, ft_strdup(args[i + 2]));
				ft_bzero(&args[i], sizeof(char *) * 3);
				return (0);
			}
			i += 2;
		}
		i++;
	}
	return (add_first(vm, player, args, ac));
}

int					parse_args(t_vm *vm, char **args, int ac)
{
	int player;

	player = 0;
	if (!args || ac < 1)
		print_error(INVALID_ARG);
	args = parse_options(vm, args, ac);
	vm->player_nb = get_player_amount(args, ac);
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
