/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:51:56 by orantane          #+#    #+#             */
/*   Updated: 2021/03/16 20:14:46 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "encoder.h"

static unsigned char	*encode_int(unsigned char *out, int i, int champ_size)
{
 	int		*nbr;
	int		len;
	int		magic;
	int		j;

    j = 0;
    magic = COREWAR_EXEC_MAGIC;
	len = 4;
	if (champ_size > 0)
		nbr = &champ_size;
	else if (champ_size == -1)
		nbr = &magic;
	else if (champ_size == 0)
		return (out);
	while (--len >= 0)
	{
		out[i + j] = *(((unsigned char*)nbr) + len);
        j++;
	}
	return (out);
}

static unsigned char	*encode_string(unsigned char *out, int i, 
										char *text, int type)
{
	int		index;

	index = 0;
	while (text && text[index])
	{
		if (type == 1 && index == PROG_NAME_LENGTH)
			print_error(8);
		if (type == 2 && index == COMMENT_LENGTH)
			print_error(8);
		out[i + index] = (unsigned char)text[index];
		index++;
	}
	while (type == 1 && index < PROG_NAME_LENGTH + 4)
		out[i + index++] = 0;
	while (type == 2 && index < COMMENT_LENGTH + 4)
		out[i + index++] = 0;
	return (out);
}

unsigned char			*encode_output(char *name, char *comment, 
										int champ_size)
{
	unsigned char	*out;
	int				i;

	i = 0;
	out = ft_memalloc(PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	out = encode_int(out, i, -1);
	i += sizeof(int);
	out = encode_string(out, i, name, 1);
	i += PROG_NAME_LENGTH + 4;
	out = encode_int(out, i, champ_size);
	i += 4;
	out = encode_string(out, i, comment, 2);
	return (out);
}
