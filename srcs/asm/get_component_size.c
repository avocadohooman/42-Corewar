/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/04 16:47:49 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete

int				check_dir_size(char *opcode)
{
	if (!strcmp(opcode, "zjmp") || !ft_strcmp(opcode, "ldi") ||
		!ft_strcmp(opcode, "sti") || !ft_strcmp(opcode, "fork") ||
		!ft_strcmp(opcode, "lldi") || !ft_strcmp(opcode, "lfork"))
		return 2;
	else
		return 4;
}

int				check_arg_type_code(char *opcode)
{
	if (!strcmp(opcode, "live") || !ft_strcmp(opcode, "zjmp") ||
		!ft_strcmp(opcode, "fork") || ft_strcmp(opcode, "fork") ||
		!ft_strcmp(opcode, "lfork"))
		return 0;
	else
		return 1;
}

int				component_type_size(char *arg, int dir_size)
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
}

void			get_component_size(t_ass *ass, t_statement *state)
{
	int dir_size;

	ass->size = 1; // statement code
	ass->size += check_arg_type_code(state->opcode);

	dir_size = check_dir_size(state->opcode);

	ass->size += component_type_size(state->arg1, dir_size);
	ass->size += component_type_size(state->arg2, dir_size);
	ass->size += component_type_size(state->arg3, dir_size);
	
	ass->statement_buff = (unsigned char*)malloc(sizeof(unsigned char) * ass->size);
	ass->statement_buff[0] = get_statement(state->opcode);
	printf("Statement final size = %d\n", ass->size);
}
