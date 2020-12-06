/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_dir_special_arguments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:43:04 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/06 17:17:26 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete
#include <limits.h>

static int			handle_zjump(t_ass *ass, char *t_dir_arg, int t_dir_size)
{
	int bytes;

	char *trimmed_arg = ft_strchr(t_dir_arg, ':');
	bytes = fetch_jmp(ass->track, &trimmed_arg[1], ass->size);
	return bytes;
}

static int			handle_live(t_ass *ass, char *t_dir_arg, int t_dir_size)
{
	int bytes;

	bytes = ass->size;
	return bytes;
}

int					handle_t_dir_special(t_ass *ass, t_statement *statement, char *t_dir_arg, int t_dir_size)
{
	int bytes;

	if (ft_strstr(t_dir_arg, "live"))
		bytes = handle_live(ass, t_dir_arg, t_dir_size);
	else if (!ft_strcmp(statement->opcode, "zjmp"))
		bytes =  handle_zjump(ass, t_dir_arg, t_dir_size);
	return bytes;
}