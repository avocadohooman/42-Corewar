/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/03/16 14:02:54 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "opcodes.h"

void		more_execute_statements(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
	if (carriage->stmt->statement == 10)
		op_ldi(carriage, arena);
	else if (carriage->stmt->statement == 11)
		op_sti(carriage, arena);
	else if (carriage->stmt->statement == 12)
		op_fork(carriage, vm, arena);
	else if (carriage->stmt->statement == 13)
		op_lld(carriage, arena);
	else if (carriage->stmt->statement == 14)
		op_lldi(carriage, arena);
	else if (carriage->stmt->statement == 15)
		op_lfork(carriage, vm, arena);
	else if (carriage->stmt->statement == 16)
		op_aff(carriage);
}

void		execute_statement(t_carriage *carriage, t_vm *vm, t_loop *loop, unsigned char *arena)
{
	if (carriage->stmt->statement == 1)
	{
		loop->nbr_live++;
		op_live(carriage, vm);
	}
	else if (carriage->stmt->statement == 2)
		op_ld(carriage, arena);
	else if (carriage->stmt->statement == 3)
		op_st(carriage, arena);
	else if (carriage->stmt->statement == 4)
		op_add(carriage);
	else if (carriage->stmt->statement == 5)
		op_sub(carriage);
	else if (carriage->stmt->statement == 6)
		op_and(carriage, arena);
	else if (carriage->stmt->statement == 7)
		op_or(carriage, arena);
	else if (carriage->stmt->statement == 8)
		op_xor(carriage, arena);
	else if (carriage->stmt->statement == 9)
		op_zjmp(carriage, arena);
	more_execute_statements(carriage, vm, arena);
}

void		kill_carriage(t_carriage *carriage)
{
	if (carriage != NULL && carriage->stmt)
		free(carriage->stmt);
	free(carriage);
	carriage = NULL;
}

void		check_carriages(t_vm *vm, t_loop *loop)
{
	t_carriage	*tmp;
	t_carriage	*next;
	t_carriage	*prev;
	int			del;

	del = 0;
	prev = NULL;
	tmp = vm->carriages;
	while (tmp != NULL)
	{
		if (tmp)
			next = tmp->next;
		if (tmp->last_live <= (tmp->cycle - loop->ctd_reset))
		{
			if (tmp == loop->head)
			{
				loop->head = tmp->next;
				vm->carriages = tmp->next;
			}
			if (prev && prev->next)
				prev->next = tmp->next;
			kill_carriage(tmp);
			tmp = next;
			vm->carry_nbr--;
		}
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
	else
		loop->cycle_to_die = loop->ctd_reset;
}

void		init_battle_loop(t_vm *vm, t_loop *loop)
{
	loop->cycle = 0;
	loop->nbr_live = 0;
	loop->cycle_to_die = CYCLE_TO_DIE;
	loop->ctd_reset = CYCLE_TO_DIE;
	loop->nbr_checks = 0;
	loop->head = vm->carriages;
}

void		battle_loop(t_vm *vm, unsigned char *arena)
{
	t_loop		loop;
	t_carriage	*tmp;
	int			carry;
	int 		tmp_nbr;

	init_battle_loop(vm, &loop);
	vm->last_live = vm->players[vm->player_nb - 1];
	while (vm->carriages != NULL && vm->carry_nbr > 0)
	{
		tmp = vm->carriages;
		carry = 0;
		tmp_nbr = vm->carry_nbr;
		while (carry < tmp_nbr)
		{
			if (tmp->stmt == NULL)
				init_stmt(tmp, arena);
			tmp->cycles_to_execute--;
	//		printf("Cycles to exec: %d\n", tmp->cycles_to_execute);
			if (tmp->stmt && tmp->cycles_to_execute == 0)
			{
				if (!(form_statement(tmp, arena)))
				{
					execute_statement(tmp, vm, &loop, arena);
					loop.head = vm->carriages;
					free(tmp->stmt);
					tmp->stmt = NULL;
					tmp->cycles_to_execute = 0;
				}
			}
			tmp->cycle = loop.cycle;
			tmp = tmp->next;
			carry++;
		}
		loop.cycle_to_die--;
		loop.cycle++;
		if (loop.cycle_to_die <= 0 && vm->carry_nbr > 0)
			check_carriages(vm, &loop);
		if (vm->dump != 0 && loop.cycle == vm->dump)
		{
			dump_arena(arena);
			exit(0);
		}
	}
}
