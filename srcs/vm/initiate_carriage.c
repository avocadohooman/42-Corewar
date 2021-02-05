/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_carriage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:54:55 by gmolin            #+#    #+#             */
/*   Updated: 2021/02/05 15:55:21 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h> // remove

t_carriage		*create_carriage(t_carriage *next, int player_id, unsigned char *position) 
{
	t_carriage     *carriage;

	if (!(carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage))))
        return (NULL);
	if (player_id <= REG_NUMBER)
		carriage->regs[0] = player_id * -1;
	carriage->pos = position;
	carriage->cycles_to_execute = -1;
	carriage->last_live = -1;
	carriage->carry_flag = 0;
	carriage->cycle = 0;
	carriage->next = next;
	return (carriage);
}

void		initiate_carriages(t_vm *vm, unsigned char *arena)
{
	t_carriage	*head;
	int         i;
	int         carriage_pos;
	
	i = 0;
	head = NULL;
	while (i < vm->player_nb)
	{
		carriage_pos = (vm->players[i]->id - 1) * (MEM_SIZE / vm->player_nb);
		head = create_carriage(head, vm->players[i]->id, &arena[carriage_pos]);
        printf("r1: %d\n", head->regs[0]);
		form_statement(head);
		op_ld(head, vm, arena);
		i++;
	}
	vm->carriages = head;
}