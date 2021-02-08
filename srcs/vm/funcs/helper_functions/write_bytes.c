/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:04:04 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 15:21:06 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
/*
** Takes a pointer to memspace (where)
** Takes a numeric value (what)
** Takes a size (size)
**
** Writes the numeric value to memspace byte by byte
**
** NOTES:
** 		Remember to apply offset to carry->pos pointer when dealing with addresses in memspace (arena)!
**			carry->pos pointer is always current statement size ahead. Offset amount is stored in carry->offset.
**		Tested with value -19 and size 2, wrote ff ed. All should be good.
** 		If you are writing a registry value, size is always 4 as REG_SIZE implicates in op.h
*/

void	write_bytes(unsigned char *where, int what, int size)
{
	int pos;
	unsigned char *buf;

//	if (size == 2)
//		printf("write_bytes: Value recieved: int: %d VS short: %hd\n", what, (short)what);
	pos = 0;
	buf = (unsigned char *)&what;
	while (size > 0)
	{
		where[pos] = buf[size - 1];
		pos++;
		size--;
	}
}
