/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:58 by gmolin            #+#    #+#             */
/*   Updated: 2021/03/16 20:30:51 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"
#include "file.h"

void		get_argument_type(t_ass *ass, t_instruction *instruction)
{
	if (instruction->statement->arg_type_req)
	{
		int	i;

		i = 0;
		ass->argument_type = 0;
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
		ass->statement_buff[ass->buff_slot] = ass->argument_type;
//		printf("Argument Type Bytecode: 0x%x\n", ass->statement_buff[ass->buff_slot]);
		ass->buff_slot++;
	}
}
