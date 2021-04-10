/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:41:06 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 14:08:50 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(t_printf *list, double nb)
{
	if (nb < 0)
		return ('-');
	if (list->flag_convert[1] == '+')
		return ('+');
	if (list->flag_convert[2] == ' ')
		return (' ');
	return ('\0');
}
