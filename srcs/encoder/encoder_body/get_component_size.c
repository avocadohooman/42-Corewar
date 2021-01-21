/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:01 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/21 20:07:23 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"
#include "file.h"
#include <stdio.h> // delete


int		op_table_redefined[17][3] =
{
	{0x01, 0, 4},
	{0x02, 1, 4},
	{0x03, 1, 4},
	{0x04, 1, 4},
	{0x05, 1, 4},
	{0x06, 1, 4},
	{0x07, 1, 4},
	{0x08, 1, 4},
	{0x09, 0, 2},
	{0x0a, 1, 2},
	{0x0b, 1, 2},
	{0x0c, 0, 2},
	{0x0d, 1, 4},
	{0x0e, 1, 2},
	{0x0f, 0, 2},
	{0x10, 1, 4},
	{0, 0, 0}
};

static int				fetch_index(unsigned char code)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (op_table_redefined[i][0] == code)
			return i;
		else if (op_table_redefined[i][0] == 0)
			return 100;
		i++;
	}
	return 100;
}

static int				component_type_size(char *arg, int dir_size)
{
	if (!arg)
		return 0;
	if (ft_strstr(arg, "%"))
		return dir_size;
	else if (ft_strstr(arg, "r"))
		return 1;
	else if (ft_strstr(arg, "-"))
		return 2;
	else
		printf("asm/get_component_size.c : Could not fetch arg size for %s!", arg);
		return 0;
}

void				get_component_size(t_ass *ass, t_statement *state, bool write)
{
	int				dir_size;
	unsigned char	statement;
	int				index;
	int				i;

	i = 0;
	ass->size = 1;
	statement = get_statement(state->opcode);
	index = fetch_index(statement);
	if (index == 100)
		printf("Index not found for %s!\n", state->opcode);
	ass->size += op_table_redefined[index][1];
	dir_size = op_table_redefined[index][2];

	// Set dir size and need of arg type code

	state->t_dir = dir_size;
	if (op_table_redefined[index][1] == 1)
		state->arg_type_req = true;
	else
		state->arg_type_req = false;
	while (i < state->number_arg)
	{
		ass->size += component_type_size(state->arguments[i], dir_size);
		i++;
	}
	if (write)
	{
		printf("Statement final size = %d\n", ass->size);
		ass->statement_buff = (unsigned char*)malloc(sizeof(unsigned char) * ass->size);
		ass->statement_buff[ass->buff_slot] = statement;
		printf("Statement Bytecode = 0x%.2x\n", ass->statement_buff[ass->buff_slot]);
		ass->buff_slot++;
	}
}
