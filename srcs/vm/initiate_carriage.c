/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_carriage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:54:55 by gmolin            #+#    #+#             */
/*   Updated: 2021/02/09 00:18:43 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h> // remove

t_carriage		*create_carriage(t_carriage *next, int player_id, unsigned char *position) 
{
	t_carriage     *carriage;

	if (!(carriage = (t_carriage*)ft_memalloc(sizeof(t_carriage))))
        print_error(7);
	if (player_id <= REG_NUMBER)
		carriage->regs[0] = player_id * -1;
	carriage->pos = position;
	carriage->next_statement = 0;
	carriage->cycles_to_execute = -1;
	carriage->last_live = -1;
	carriage->carry_flag = 0;
	carriage->cycle = 0;
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
	while (i < vm->player_nb)
	{
		carriage_pos = (vm->players[i]->id - 1) * (MEM_SIZE / vm->player_nb);
		head = create_carriage(head, vm->players[i]->id, &arena[carriage_pos]);
		head->abs_pos = carriage_pos;
		vm->carry_nbr++;
        printf("r1: %d\n", head->regs[0]);
		
		form_statement(head, arena);
		op_sti(head, arena); 
		free(head->stmt);
		head->stmt = NULL;
		
		form_statement(head, arena);
		op_live(head, vm);
		free(head->stmt);
		head->stmt = NULL;
		
		form_statement(head, arena);
		op_ld(head, arena);
		free(head->stmt);
		head->stmt = NULL;
		printf("Carry flag is %d\n", head->carry_flag);

		form_statement(head, arena);
		op_zjmp(head, arena);
		free(head->stmt);
		head->stmt = NULL;

		form_statement(head, arena);
		printf("Player DONE\n\n\n");
		i++;
	}
	vm->carriages = head;
}
