/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:04:04 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 14:14:27 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	write_bytes	(MEMSPACE GUARDIAN)
**
**	Takes the whole memspace (arena)
**	Takes a index to memspace (where)
**	Takes a numeric value (what)
**	Takes a size (size)
**
**	Writes the numeric value to memspace byte by byte
**	while wrapping to index 0 if index > MEM_SIZE
**	this is achieved using modulo MEM_SIZE to index
**
**	NOTES:
**
**		Tested with value -19 and size 2, wrote ff ed. All should be good.
**		Tested with also with max index, and wrote to index 0 onwards, so wrapping works.
** 		If you are writing a registry value, size is always 4 as REG_SIZE implicates in op.h
**
**	Retuns nothing
*/

void	write_bytes(unsigned char *arena, int where, int what, int size)
{
	unsigned char *buf;

	buf = (unsigned char *)&what;
	if (where < 0)
		where += MEM_SIZE;
	while (size > 0)
	{
		where %= MEM_SIZE;
		arena[where] = buf[size - 1];
		size--;
		where++;
	}
}
