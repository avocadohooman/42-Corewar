/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:51:56 by orantane          #+#    #+#             */
/*   Updated: 2020/12/04 15:55:19 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "asm.h"
#include "error.h"

t_file		*encode_int(t_file *buf, int champ_size, int i)
{
	unsigned int	nbr;
	int				len;

	len = 4;
	if (champ_size)
		nbr = champ_size;
	else if (champ_size == -1)
		nbr = COREWAR_EXEC_MAGIC;
	else if (champ_size == 0)
		nbr = 0;
	while (--len >= 0)
		buf->data[i + len] = *(((unsigned char *)nbr) + len);
	return (buf);
}

t_file		*encode_string(t_file *buf)
{
	return (buf);
}

void		encode_output(t_file *buf, int champ_size)
{
	int		i;

	encode_int(buf, 0, 0);
	i += 4;
	encode_string(buf);
	encode_int(buf, champ_size, i);
	encode_string(buf);
	return (buf);
}