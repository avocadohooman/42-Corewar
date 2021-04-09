/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:32:53 by seronen           #+#    #+#             */
/*   Updated: 2021/04/10 00:31:55 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		new_player(t_vm *vm, int id, char *name)
{
	t_player *new;

	if (!name)
		print_error(INVALID_ARG);
	if (!(new = ft_memalloc(sizeof(t_player))))
		print_error(MALLOC);
	new->id = id;
	new->file_name = name;
	ft_bzero(&(new->name), PROG_NAME_LENGTH + 1);
	ft_bzero(&(new->comment), COMMENT_LENGTH + 1);
	new->exec_code = NULL;
	vm->players[id - 1] = new;
}

int			get_player_amount(char **args, int ac)
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
