/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:26:21 by seronen           #+#    #+#             */
/*   Updated: 2021/02/09 02:16:35 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
