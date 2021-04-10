/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:51:28 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 15:45:07 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_specifier(t_printf *list)
{
	size_t	j;

	j = 0;
	while (list->specifier_list[j])
	{
		if (list->f_copy[list->i] == list->specifier_list[j])
			list->specifier_char = list->specifier_list[j];
		j++;
	}
	return (list);
}
