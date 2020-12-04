/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:58 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/04 17:28:27 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete

void		get_argument_type(t_ass *ass, t_instruction *instruction)
{
	int	i;

	i = 0;
	while (i < instruction->statement->number_arg)
	{
		if (instruction->statement->arguments[i][0] == 'r')
			ass->argument_type |= 1UL << (6 - (i + i));
		else if (instruction->statement->arguments[i][0] == '%')
			ass->argument_type |= 1UL << (7 - (i + i));
		else if (instruction->statement->arguments[i][0] == '-')
		{
			ass->argument_type |= 1UL << (7 - (i + i));
			ass->argument_type |= 1UL << (6 - (i + i));
		}
		i++;
	}
}