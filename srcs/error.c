/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:11:42 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 23:12:40 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*g_errors[] = {"Usage: ./asm [champion_file.s]", "Missing argument!",
						"three", "File could not be opened.","Buffer Error", 
						"Get Next Line Error"};

void	print_error(t_error_type type)
{
	ft_putendl(g_errors[type]);
	exit(0);
}
