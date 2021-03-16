/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/03/16 19:30:52 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

void		kill_carriage(t_carriage *carriage)
{
	if (carriage != NULL && carriage->stmt)
		free(carriage->stmt);
	free(carriage);
	carriage = NULL;
}

void		cycle_carriages(t_vm *vm, t_loop *loop)
{
	while (loop->tmp != NULL)
	{
		if (loop->tmp)
			loop->next = loop->tmp->next;
		if (loop->tmp->last_live <= (loop->tmp->cycle - loop->ctd_reset))
		{
			if (loop->tmp == loop->head)
			{
				loop->head = loop->tmp->next;
				vm->carriages = loop->tmp->next;
			}
			if (loop->prev && loop->prev->next)
				loop->prev->next = loop->tmp->next;
			kill_carriage(loop->tmp);
			loop->tmp = loop->next;
			vm->carry_nbr--;
		}
		else
		{
			loop->prev = loop->tmp;
			loop->tmp = loop->next;
		}
	}
}

void		check_carriages(t_vm *vm, t_loop *loop)
{
	loop->prev = NULL;
	loop->tmp = vm->carriages;
	cycle_carriages(vm, loop);
	if (loop->nbr_live >= NBR_LIVE || ++loop->nbr_checks >= MAX_CHECKS)
	{
		loop->ctd_reset -= CYCLE_DELTA;
		loop->cycle_to_die = loop->ctd_reset;
		loop->nbr_checks = 0;
		loop->nbr_live = 0;
	}
	else
		loop->cycle_to_die = loop->ctd_reset;
}
