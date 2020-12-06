/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:57:33 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/06 17:29:27 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete
#include <limits.h>

static void		handle_t_ind(t_ass *ass, char *t_ind_arg)
{
	short bytes;

	bytes = ft_atoi(t_ind_arg);
	ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[1];
	ass->buff_slot++;
	ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[0];
	ass->buff_slot++;
}

static void		handle_t_dir(t_ass *ass, t_statement *statement, char *t_dir_arg)
{
	int				bytes;

	bytes = ft_atoi(ft_strchr(t_dir_arg, '%') + 1);
	if (!ft_strcmp(statement->opcode, "zjmp") || ft_strstr(t_dir_arg, "live"))
		bytes = handle_t_dir_special(ass, statement, t_dir_arg, statement->t_dir);
	if (statement->t_dir == 4)
	{
		ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[3];
		ass->buff_slot++;
		ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[2];
		ass->buff_slot++;
	}
	ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[1];
	ass->buff_slot++;
	ass->statement_buff[ass->buff_slot] = ((unsigned char*)&bytes)[0];
	ass->buff_slot++;
}

static void		handle_t_reg(t_ass *ass, char *t_reg_arg)
{
	ass->statement_buff[ass->buff_slot] = ft_atoi(ft_strchr(t_reg_arg, 'r') + 1);
	ass->buff_slot++;
}

void			get_arguments(t_ass *ass, t_statement *statement)
{
	int i;

	i = 0;
	while (i < statement->number_arg)
	{
		if (ft_strchr(statement->arguments[i], 'r'))
			handle_t_reg(ass, statement->arguments[i]);
		else if (ft_strchr(statement->arguments[i], '%'))
			handle_t_dir(ass, statement, statement->arguments[i]);
		else
			handle_t_ind(ass, statement->arguments[i]);
		i++;
	}
}