/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:53 by seronen           #+#    #+#             */
/*   Updated: 2021/03/25 04:20:04 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		new_player(t_vm *vm, int id, char *name)
{
	t_player *new;

	if (!name)
		print_error(INVALID_ARG);
	if (!(new = malloc(sizeof(t_player))))
		print_error(MALLOC);
	new->id = id;
	new->file_name = name;
	bzero(&(new->name), PROG_NAME_LENGTH + 1);
	bzero(&(new->comment), COMMENT_LENGTH + 1);
	new->exec_code = NULL;
	vm->players[id - 1] = new;
}

int			get_player_amount(t_vm *vm, char **args, int ac)
{
	int i;
	int amount;

	i = 0;
	amount = 0;
	while (i < ac)
	{
		if (args[i] && !ft_strcmp("-n", args[i]))
			i++;
		else if (args[i])
			amount++;
		i++;
	}
	if (amount < MIN_PLAYERS)
		print_error(INVALID_ARG);
	return (amount);
}
