/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:51:56 by orantane          #+#    #+#             */
/*   Updated: 2020/12/05 16:53:05 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"

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
		nbr = 0;
	while (--len >= 0)
	{
		out[i + j] = *(((unsigned char*)nbr) + len);
        j++;
	}
	return (out);
}

static unsigned char	*encode_string(unsigned char *out, int i, 
										unsigned char *text, int type)
{
	int		index;

	index = 0;
	while (text && text[index])
	{
		if (type == 1 && index == PROG_NAME_LENGTH)
			print_error("Champion's name is too long!");
		if (type == 2 && index == COMMENT_LENGTH)
			print_error("Comment is too long");
		out[i + index] = text[index];
		index++;
	}
	while (type == 1 && index < PROG_NAME_LENGTH + 4)
		out[i + index++] = 0;
	while (type == 2 && index < COMMENT_LENGTH + 4)
		out[i + index++] = 0;
	return (out);
}

unsigned char			*encode_output(t_header *strings, int champ_size)
{
	unsigned char	*out;
	int				i;
	size_t			size;

	size = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH;
	i = 0;
	out = ft_memalloc(size);
	i = 0;
	out = encode_int(out, i, -1);
	i += sizeof(int);
	out = encode_string(out, i, strings->prog_name, 1);
	i += PROG_NAME_LENGTH + 4;
	out = encode_int(out, i, champ_size);
	i += 4;
	out = encode_string(out, i, strings->comment, 2);
	return (out);
}