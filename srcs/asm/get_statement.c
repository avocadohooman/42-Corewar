/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_statement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:27 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/04 14:56:42 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete


int 		get_statement(char *statement)
{
	if (!ft_strcmp("sti", statement))
		return 0x0b;
	else if (!ft_strcmp("ld", statement))
		return 0x02;
	else
		return NULL;
}