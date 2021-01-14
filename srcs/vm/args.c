/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:46:01 by seronen           #+#    #+#             */
/*   Updated: 2021/01/14 13:26:47 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void			new_player(t_vm *vm, int id, char *name)
{
	t_player *new;

	if (!(new = malloc(sizeof(t_player))))
		print_error(MALLOC);
	new->file_name = name;
	new->id = id;
	vm->players[id - 1] = new;
}

static int			add_first(t_vm *vm, int player, char **args, int ac)
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

static int			validate_nb(char *str, int player)
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
	if (nb < 1)
		print_error(INVALID_ARG);
	if (player && (nb < player || nb > MAX_PLAYERS))
		print_error(INVALID_ARG);
	return (nb);
}

static int     		arguments(t_vm *vm, int player, char **args, int ac)
{
	int i;
	int pos;

	i = 0;
	while (i++ < ac)
	{
		if (!vm->dump && args[i] && !ft_strcmp("-dump", args[i]))
		{
			vm->dump = validate_nb(args[i + 1], 0);
			printf("Found dump with value: %d\n", vm->dump);
			i += 2;
		}
		if (args[i] && !ft_strcmp(args[i], "-n"))
		{
			pos = validate_nb(args[i + 1], player);
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

int					get_players(t_vm *vm, char **args, int ac)
{
	int player;

	player = 0;
	if (!args)
		print_error(INVALID_ARG);
	while (player < MAX_PLAYERS)
	{
		arguments(vm, player + 1, args, ac);
		player++;
	}
	return (0);
}