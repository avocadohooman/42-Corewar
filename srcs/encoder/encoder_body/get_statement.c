/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_statement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:27 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/22 22:18:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"
#include "file.h"
#include <stdio.h> // delete

unsigned char		get_statement(char *statement)
{
	if (!ft_strcmp("live", statement))
		return 0x01;
	else if (!ft_strcmp("ld", statement))
		return 0x02;
	else if (!ft_strcmp("st", statement))
		return 0x03;
	else if (!ft_strcmp("add", statement))
		return 0x04;
	else if (!ft_strcmp("sub", statement))
		return 0x05;
	else if (!ft_strcmp("and", statement))
		return 0x06;
	else if (!ft_strcmp("or", statement))
		return 0x07;
	else if (!ft_strcmp("xor", statement))
		return 0x08;
	else if (!ft_strcmp("zjmp", statement))
		return 0x09;
	else if (!ft_strcmp("ldi", statement))
		return 0x0a;
	else if (!ft_strcmp("sti", statement))
		return 0x0b;
	else if (!ft_strcmp("fork", statement))
		return 0x0c;
	else if (!ft_strcmp("lld", statement))
		return 0x0d;
	else if (!ft_strcmp("lldi", statement))
		return 0x0e;
	else if (!ft_strcmp("lfork", statement))
		return 0x0f;
	else if (!ft_strcmp("aff", statement))
		return 0x10;
	else
//		print_error(INVALID_STATEMENT);
		return 0x0;
}
