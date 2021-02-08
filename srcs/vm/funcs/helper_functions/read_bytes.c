/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:26:21 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 22:21:47 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		read_bytes(unsigned char *arena, int where, int size)
{
	int index;
	unsigned char buf[4];

	index = 0;
	ft_memset(buf, 0, 4);
	if (size == 2)
		index = 2;
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
