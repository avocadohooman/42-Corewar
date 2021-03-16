/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memspace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:55:54 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 14:04:46 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	MEMSPACE GUARDIAN
**
**	fetch_position
**
**	Args:
**		– Memspace in whole (arena)
**		– Carriage (we will be using the carry->abs_pos)
**		– Value of how far are we moving (how_far)
**
**	Checks that next position does not go over the memspace limits,
**	if it does, it loops the address around.
**	F.ex. carry->abs_pos 0, how_far -4, loops to MEM_SIZE - 4
**
**	Goal is to keep addresses inside memspace to avoid segfaults :)
**	Updates carry->abs_pos to be the new place
**	Returns a pointer to the new valid address in memspace
**
**	Super useful I promise!
*/

int				real_modulo(int position, int value, int modulo)
{
	int res;

	res = position + (value % modulo);
//	printf("mod res: %d, res bef trunc: %d\n", value % modulo, res);
	res %= MEM_SIZE;
	res = res >= MEM_SIZE ? res - MEM_SIZE : res;
	res = res < 0 ? res + MEM_SIZE : res;
//	printf("res: %d\n", res);
	return (res);
}

unsigned char   *fetch_position(unsigned char *arena, int pos, int where, int modulo)
{
	int new;

	new = real_modulo(pos, where, modulo);
	return (&arena[new]);
}
