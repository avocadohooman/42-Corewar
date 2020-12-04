/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:58 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/04 14:57:16 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete

void		get_argument_type(t_ass *ass, char **arguments)
{
	if (!ft_strcmp("sti", arguments[0]))
		ass->argument_type_code = 0x68;
	else if (!ft_strcmp("ld", arguments[0])) 
		ass->argument_type_code = 0x90;

}