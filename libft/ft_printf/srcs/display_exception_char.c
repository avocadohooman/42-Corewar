/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_exception_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:16:58 by hopham            #+#    #+#             */
/*   Updated: 2019/12/11 11:21:28 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_exception_char(char c, t_printf *list)
{
	if (c == '+')
	{
		write(1, "+", 1);
		list->len++;
	}
	if (c == ' ')
	{
		write(1, " ", 1);
		list->len++;
	}
}
