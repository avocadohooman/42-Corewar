/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:11:42 by orantane          #+#    #+#             */
/*   Updated: 2021/01/14 13:20:07 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

char	*g_errors[] = {"Usage: ./asm [champion_file.s]", "Missing argument!",
						"three", "File could not be opened.","Buffer Error", 
						"Get Next Line Error", "Invalid argument!", "Malloc error!"};

void	print_error(t_error_type type)
{
	ft_putendl(g_errors[type]);
	exit(0);
}
