/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:24:05 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:24:36 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "opcodes.h"

int			lookup_opcode(char *str)
{
	int		i;

	i = 0;
	while (opcode_table[i].literal)
	{
		if (!ft_strcmp(opcode_table[i].literal, str))
			return (i);
		i++;
	}
	return (-1);
}

int			check_argument(int options, int received)
{
	if ((options & received) == received)
		return (1);
	return (0);
}

int			is_label_char(char c)
{
	if (!c)
		return (0);
	if (ft_strchr(LABEL_CHARS, c))
		return (1);
	return (0);
}
