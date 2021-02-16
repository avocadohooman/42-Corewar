/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_carriage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:54:55 by gmolin            #+#    #+#             */
/*   Updated: 2021/02/16 20:09:34 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h> // remove

t_carriage		*create_carriage(t_vm *vm, t_carriage *next, int player_id) 
{
	t_carriage     *carriage;

	if (!(carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage))))
        print_error(7);
	if (player_id <= REG_NUMBER)
		carriage->regs[0] = player_id * -1;
	carriage->id = vm->id_tracker;
	vm->id_tracker++;
	carriage->cycle = 0;
	carriage->next_statement = 0;
	carriage->cycles_to_execute = -1;
	carriage->last_live = -1;
	carriage->carry_flag = 0;
	carriage->next = next;
	carriage->stmt = NULL;
	return (carriage);
}

void		initiate_carriages(t_vm *vm, unsigned char *arena)
{
	t_carriage	*head;
	int         i;
	int         carriage_pos;
	
	i = 0;
	head = NULL;
	vm->id_tracker = 0;
	while (i < vm->player_nb)
	{
		carriage_pos = (vm->players[i]->id - 1) * (MEM_SIZE / vm->player_nb);
		head = create_carriage(vm, head, vm->players[i]->id);
		head->abs_pos = carriage_pos;
		vm->carry_nbr++;
		form_statement(head, arena);
		i++;
	}
	vm->carriages = head;
}
