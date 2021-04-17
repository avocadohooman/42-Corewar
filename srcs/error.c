/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:42:42 by gmolin            #+#    #+#             */
/*   Updated: 2021/04/14 11:44:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*g_errors[] = {"Usage: ./asm [champion_file.s]", "Missing argument!",
	"three", "File could not be opened.", "Buffer Error",
	"Get Next Line Error", "Invalid argument!",
	"Malloc error!", "Name or comment is too long.",
	"label not found"};

void	print_error(int type)
{
	ft_putendl(g_errors[type]);
	exit(EXIT_FAILURE);
}
