/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/02/06 14:51:36 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		more_execute_statements(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	if (carriage->stmt->statement == 10)
		return (op_ldi(carriage, vm, arena));
	else if (carriage->stmt->statement == 11)
		return (op_sti(carriage, vm, arena));
	else if (carriage->stmt->statement == 12)
		return (op_fork(carriage, vm, arena));
	else if (carriage->stmt->statement == 13)
		return (op_lld(carriage, vm, arena));
	else if (carriage->stmt->statement == 14)
		return (op_lldi(carriage, vm, arena));
	else if (carriage->stmt->statement == 15)
		return (op_lfork(carriage, vm, arena));
	else if (carriage->stmt->statement == 16)
		return (op_aff(carriage, vm, arena));
}

void		execute_statement(t_carriage *carriage, t_vm *vm, t_loop *loop, unsigned char *arena)
{
	if (carriage->stmt->statement == 1)
	{
		loop->nbr_live++;
		return (op_live(carriage, vm, arena));
	}
	else if (carriage->stmt->statement == 2)
		return (op_ld(carriage, vm, arena));
	else if (carriage->stmt->statement == 3)
		return (op_st(carriage, vm, arena));
	else if (carriage->stmt->statement == 4)
		return (op_add(carriage, vm, arena));
	else if (carriage->stmt->statement == 5)
		return (op_sub(carriage, vm, arena));
	else if (carriage->stmt->statement == 6)
		return (op_and(carriage, vm, arena));
	else if (carriage->stmt->statement == 7)
		return (op_or(carriage, vm, arena));
	else if (carriage->stmt->statement == 8)
		return (op_xor(carriage, vm, arena));
	else if (carriage->stmt->statement == 9)
		return (op_zjump(carriage, vm, arena));
	more_execute_statements(carriage, vm, arena);
}

t_carriage		*kill_carriage(t_carriage *carriage, t_carriage *prev, t_carriage *next)
{
	if (prev != NULL)
		prev->next = next;
	if (carriage->stmt)
		free(carriage->stmt);
	free(carriage);
	return (next);
}

void		check_carriages(t_vm *vm, t_loop *loop)
{
	t_carriage	*tmp;
	t_carriage	*next;
	t_carriage	*prev;

	tmp = vm->carriages;
	prev = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->last_live <= (tmp->cycle - loop->ctd_reset))
			tmp = kill_carriage(tmp, prev, next);
		else
		{
			prev = tmp;
			tmp = next;
		}
	}
	if (loop->nbr_live >= NBR_LIVE || ++loop->nbr_checks >= MAX_CHECKS)
	{
		loop->ctd_reset -= CYCLE_DELTA;
		loop->cycle_to_die = loop->ctd_reset;
		loop->nbr_checks = 0;
		loop->nbr_live = 0;
	}
}

void		init_battle_loop(t_vm *vm, t_loop *loop, unsigned char *arena)
{
	loop->cycle = 0;
	loop->nbr_live = 0;
	loop->cycle_to_die = CYCLE_TO_DIE;
	loop->ctd_reset = CYCLE_TO_DIE;
	loop->nbr_checks = 0;
	initiate_carriages(vm, arena);
}

void		battle_loop(t_vm *vm, unsigned char *arena)
{
	t_loop		loop;
	t_carriage	*tmp;

	init_battle_loop(vm, &loop, arena);
	while (vm->carriages != NULL)
	{
		tmp = vm->carriages;
		while (tmp)
		{
			if (tmp->cycles_to_execute == -1)
				form_statement(tmp);
			else if (tmp->cycles_to_execute == 0)
			{
				execute_statement(tmp, vm, &loop, arena);
				free(tmp->stmt);
				tmp->stmt = NULL;
				form_statement(tmp);
			}
			else if (tmp->cycles_to_execute > 0)
				tmp->cycles_to_execute--;
			tmp->cycle++;
			tmp = tmp->next;
		}
		loop.cycle++;	// The cycle is one higher than it actually is while in the check_carriages function, keep that in mind.
		if (loop.cycle_to_die == 0)
			check_carriages(vm, &loop);
		loop.cycle_to_die--;
	}
}