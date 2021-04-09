/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/04/09 16:57:15 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		more_execute_statements(t_carriage *carriage, t_vm *vm,
									unsigned char *arena)
{
	if (carriage->stmt->statement == 10)
		op_ldi(carriage, arena);
	else if (carriage->stmt->statement == 11)
		op_sti(carriage, arena);
	else if (carriage->stmt->statement == 12)
		op_fork(carriage, vm, arena);
	else if (carriage->stmt->statement == 13)
		op_lld(carriage, arena, vm->options[LLD_FIX]);
	else if (carriage->stmt->statement == 14)
		op_lldi(carriage, arena);
	else if (carriage->stmt->statement == 15)
		op_lfork(carriage, vm, arena);
	else if (carriage->stmt->statement == 16)
		op_aff(carriage);
}

void		execute_statement(t_carriage *carriage, t_vm *vm,
								t_loop *loop, unsigned char *arena)
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

void		init_battle_loop(t_vm *vm, t_loop *loop)
{
	loop->cycle = 0;
	loop->nbr_live = 0;
	loop->cycle_to_die = CYCLE_TO_DIE;
	loop->ctd_reset = CYCLE_TO_DIE;
	loop->nbr_checks = 0;
	loop->head = vm->carriages;
	loop->carry = 0;
	loop->tmp = vm->carriages;
	loop->tmp_nbr = vm->carry_nbr;
	loop->next = NULL;
	loop->prev = NULL;
}

void		carriage_loop(t_vm *vm, t_loop *loop, unsigned char *arena)
{
	while (loop->carry < loop->tmp_nbr)
	{
		if (loop->tmp->stmt == NULL)
			init_stmt(loop->tmp, arena);
		loop->tmp->cycles_to_execute--;
		if (loop->tmp->stmt && loop->tmp->cycles_to_execute == 0)
		{
			if (!(form_statement(loop->tmp, arena)))
			{
				execute_statement(loop->tmp, vm, loop, arena);
				loop->head = vm->carriages;
				free(loop->tmp->stmt);
				loop->tmp->stmt = NULL;
				loop->tmp->cycles_to_execute = 0;
			}
		}
		loop->tmp->cycle = loop->cycle;
		loop->tmp = loop->tmp->next;
		loop->carry++;
	}
}

void		battle_loop(t_vm *vm, unsigned char *arena)
{
	t_loop		loop;

	init_battle_loop(vm, &loop);
	vm->last_live = vm->players[vm->player_nb - 1];
	while (vm->carriages != NULL && vm->carry_nbr > 0)
	{
		loop.tmp = vm->carriages;
		loop.carry = 0;
		loop.tmp_nbr = vm->carry_nbr;
		if (vm->options[DUMP] != 0 &&
			loop.cycle == vm->options[DUMP] - 1)
		{
			dump_arena(arena);
			exit(0);
		}
		carriage_loop(vm, &loop, arena);
		loop.cycle_to_die--;
		loop.cycle++;
		if (loop.cycle_to_die <= 0 && vm->carry_nbr > 0)
			check_carriages(vm, &loop);
	}
}
