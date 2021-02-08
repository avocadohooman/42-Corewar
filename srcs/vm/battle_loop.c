/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:46:01 by orantane          #+#    #+#             */
/*   Updated: 2021/02/08 13:55:31 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		more_execute_statements(t_carriage *carriage, t_vm *vm)
{
/*	if (carriage->stmt->statement == 10)
		op_ldi(carriage, vm);
	else if (carriage->stmt->statement == 11)
		op_sti(carriage, vm);
	else if (carriage->stmt->statement == 12)
		op_fork(carriage, vm);
	else if (carriage->stmt->statement == 13)
		op_lld(carriage, vm);
	else if (carriage->stmt->statement == 14)
		op_lldi(carriage, vm);
	else if (carriage->stmt->statement == 15)
		op_lfork(carriage, vm);
	else if (carriage->stmt->statement == 16)
		op_aff(carriage, vm); */
}

void		execute_statement(t_carriage *carriage, t_vm *vm, t_loop *loop)
{
/*	if (carriage->stmt->statement == 1)
	{
		loop->nbr_live++;
		op_live(carriage, vm);
	}
	else if (carriage->stmt->statement == 2)
		op_ld(carriage);
	else if (carriage->stmt->statement == 3)
		op_st(carriage);
	else if (carriage->stmt->statement == 4)
		op_add(carriage);
	else if (carriage->stmt->statement == 5)
		op_sub(carriage);
	else if (carriage->stmt->statement == 6)
		op_and(carriage);
	else if (carriage->stmt->statement == 7)
		op_or(carriage,);
	else if (carriage->stmt->statement == 8)
		op_xor(carriage);
	else if (carriage->stmt->statement == 9)
		op_zjump(carriage); */
	more_execute_statements(carriage, vm);
}

t_carriage		*kill_carriage(t_carriage *carriage, t_carriage *prev, t_carriage *next) // This needs to be fixed after the op-functions are done.
{
//	if (prev != NULL)
//		prev->next = next;
//	if (carriage && carriage->stmt)
//		free(carriage->stmt);
//	free(carriage);
//	carriage = NULL;
	return (next);
}

void		check_carriages(t_vm *vm, t_loop *loop)
{
	t_carriage	*tmp;
	t_carriage	*next;
	t_carriage	*prev;
	int			carry;

	carry = 0;
	tmp = vm->carriages;
	printf("Starting carriage check!\n");
	while (carry < vm->carry_nbr && tmp != NULL)
	{
		if (tmp && tmp->next)
			next = tmp->next;
		if (tmp->last_live <= (tmp->cycle - loop->ctd_reset))
		{
			if (tmp == loop->head)
				loop->head = tmp->next;
			printf("Carriage for player %d is KIA, RIP!\n", (tmp->regs[0] * -1));
			tmp = kill_carriage(tmp, prev, next);
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
	printf("Carriage check done!\n");
}

void		init_battle_loop(t_vm *vm, t_loop *loop, unsigned char *arena)
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

	init_battle_loop(vm, &loop, arena);
	while (vm->carriages != NULL)
	{
		tmp = vm->carriages;
		carry = 0;
		while (carry < vm->carry_nbr)
		{
			if (tmp->cycles_to_execute == 0)
			{
				execute_statement(tmp, vm, &loop);
				free(tmp->stmt);
				tmp->stmt = NULL;
				form_statement(tmp);
			}
			else if (tmp->cycles_to_execute > 0)
				tmp->cycles_to_execute--;
			tmp->cycle++;
			tmp = tmp->next;
			carry++;
		}
		loop.cycle++;	// The cycle is one higher than it actually is while in the check_carriages function, keep that in mind.
		if (loop.cycle_to_die == 0)
			check_carriages(vm, &loop);
		loop.cycle_to_die--;
		printf("Cycle %d\n", loop.cycle);
//		if (loop.cycle == 150)
//			exit(1);
	}
}