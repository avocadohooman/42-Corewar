/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:29:13 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 15:44:25 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_field_width(t_printf *list)
{
	list->width = 0;
	while (list->f_copy[list->i] >= '0' && list->f_copy[list->i] <= '9')
	{
		list->width = list->width * 10 + (list->f_copy[list->i] - 48);
		list->i++;
	}
	return (list);
}
