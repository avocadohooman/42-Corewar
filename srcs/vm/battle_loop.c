/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/02/09 20:35:41 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	{
		printf("Jumping!\n");
		op_zjmp(carriage, arena);
	}
	more_execute_statements(carriage, vm, arena);
}

void		kill_carriage(t_carriage *carriage) // This needs to be fixed after the op-functions are done.
{
//	printf("No crash in kill_carriage!\n");
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
	printf("Starting carriage check!\n");
	while (tmp != NULL)
	{
		if (tmp)
			next = tmp->next;
		if (tmp->last_live <= (tmp->cycle - loop->ctd_reset))
		{
			if (tmp == loop->head)
				loop->head = tmp->next;
			if (prev && prev->next)
				prev->next = tmp->next;
			printf("Carriage for player %d was killed, RIP!\n", (tmp->regs[0] * -1));
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
		printf("Cycle to die is lowered, new value is %d\n", loop->ctd_reset);
		loop->cycle_to_die = loop->ctd_reset;
		loop->nbr_checks = 0;
		loop->nbr_live = 0;
	}
	else
		loop->cycle_to_die = loop->ctd_reset;
	printf("Carriage check done!\n");
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

	init_battle_loop(vm, &loop);
	while (vm->carriages != NULL && vm->carry_nbr > 0)
	{
		tmp = vm->carriages;
		carry = 0;
		int tmp_nbr = vm->carry_nbr;	// Assign a tmp value to carry_nbr if it changes (f.ex. when fork is executed)
		while (carry < tmp_nbr)
		{
			if (tmp->stmt == NULL)
				form_statement(tmp, arena);
			if (tmp->cycles_to_execute == 1)
			{
				execute_statement(tmp, vm, &loop, arena);
				free(tmp->stmt);
				tmp->stmt = NULL;
				form_statement(tmp, arena);
			}
			else if (tmp->cycles_to_execute > 1)
				tmp->cycles_to_execute--;
			tmp->cycle++;
			tmp = tmp->next;
			carry++;
		}
		loop.cycle++;	// The cycle is one higher than it actually is while in the check_carriages function, keep that in mind.
		if (loop.cycle_to_die <= 0 && vm->carry_nbr > 0)
			check_carriages(vm, &loop);
		loop.cycle_to_die--;
		printf("Cycle %d\n", loop.cycle);
//		if (loop.cycle == 10000)
//			exit(1);
	}
}