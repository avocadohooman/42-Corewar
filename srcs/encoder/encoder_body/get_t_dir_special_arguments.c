/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_dir_special_arguments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:43:04 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/10 13:42:53 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"
#include "file.h"
#include <limits.h>

int					handle_t_dir_label(t_ass *ass, t_statement *statement, char *t_dir_arg, int t_dir_size)
{
	int bytes;

	if (fetch_jmp(ass->track, t_dir_arg, statement->pos))
		return bytes = fetch_jmp(ass->track, t_dir_arg, t_dir_size);
	return 0;
}