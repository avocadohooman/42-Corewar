/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:48:06 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 15:46:09 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_convert(t_printf *list)
{
	size_t	j;

	j = 0;
	while (list->flags[j])
	{
		while (list->flags[j] == list->f_copy[list->i])
		{
			while (list->f_copy[list->i] == '-' && list->i++)
				list->flag_convert[0] = '-';
			while (list->f_copy[list->i] == '+' && list->i++)
				list->flag_convert[1] = '+';
			while (list->f_copy[list->i] == ' ' && list->i++)
				list->flag_convert[2] = ' ';
			while (list->f_copy[list->i] == '0' && list->i++)
				list->flag_convert[3] = '0';
			while (list->f_copy[list->i] == '#' && list->i++)
				list->flag_convert[4] = '#';
			j = 0;
		}
		j++;
	}
	return (list);
}
