/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:58 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/05 14:54:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"

void		get_argument_type(t_ass *ass, t_instruction *instruction)
{
	int	i;

	i = 0;
	while (i < instruction->statement->number_arg)
	{
		if (ft_strchr(instruction->statement->arguments[i], 'r'))
			ass->argument_type |= 1UL << (6 - (i + i));
		else if (ft_strchr(instruction->statement->arguments[i], '%'))
			ass->argument_type |= 1UL << (7 - (i + i));
		else
		{
			ass->argument_type |= 1UL << (7 - (i + i));
			ass->argument_type |= 1UL << (6 - (i + i));
		}
		i++;
	}
	ass->statement_buff[1] = ass->argument_type;
}
