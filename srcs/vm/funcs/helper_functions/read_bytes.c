/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:26:21 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 14:14:12 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	read_bytes (MEMSPACE GUARDIAN)
**
**	Takes the whole memspace (arena)
**	Takes a index to memspace (where)
**	Takes a size (size)
**
**	Reads the memspace byte by byte from index (where) onwards
**		while wrapping to index - MEM_SIZE if index > MEM_SIZE
**		this is achieved using modulo MEM_SIZE to index,
**		and wrapping to MEM_SIZE -index, if index < 0
**
**		In practice, if we have a index MEM_SIZE + 2, it converts to index 2.
**		And if the index is -2, it converts to MEM_SIZE - 2.
**
**		Uses a buffer to store the bytes read.
**
**	NOTES:
**		Tested with different values, including reading 4 bytes at index MEM_SIZE -2, All should be good.
**		In case the (where) is between 0 & MEM_SIZE, bytes are read normally.
**
**	Returns a integer formed from the bytes read.
*/

int		read_bytes(unsigned char *arena, int where, int size)
{
	int index;
	unsigned char buf[4];

	index = 0;
	if (where < 0)
		where += MEM_SIZE;
	ft_memset(buf, 0, 4);
	index = 4 - size;
	while (size > 0)
	{
		where %= MEM_SIZE;
		buf[index] = arena[where];
		size--;
		where++;
		index++;
	}
	return (convert_4_bytes(buf));
}
