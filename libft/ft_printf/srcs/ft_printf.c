/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:58:24 by hopham            #+#    #+#             */
/*   Updated: 2020/02/24 16:24:00 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static t_printf	*initialize(t_printf *list)
{
	list->len = 0;
	list->i = 0;
	list->flags = "0# +-";
	list->specifier_list = "cspdiouxXf%";
	list->len_mods = "lhL";
	list->specifier_char = '\0';
	list->f_copy = (char *)list->format;
	return (list);
}

static t_printf	*reintialize(t_printf *list)
{
	list->specifier_char = '\0';
	list->flag_convert[0] = '\0';
	list->flag_convert[1] = '\0';
	list->flag_convert[2] = '\0';
	list->flag_convert[3] = '\0';
	list->flag_convert[4] = '\0';
	list->len_mods_convert[0] = '\0';
	list->len_mods_convert[1] = '\0';
	list->precision = -1;
	list->width = 0;
	return (list);
}

static int		parse(t_printf *list)
{
	if (ft_strcmp(list->f_copy, "%") == 0)
		return (0);
	while (list->f_copy[list->i] != '\0')
	{
		if (list->f_copy[list->i] == '%')
		{
			reintialize(list);
			treatment(list);
		}
		else
		{
			write(1, &list->f_copy[list->i], 1);
			list->len++;
		}
		if (list->f_copy[list->i] == '\0')
			break ;
		list->i++;
	}
	return (list->len);
}

int				ft_printf(const char *format, ...)
{
	t_printf	*list;

	if (!(list = (t_printf*)ft_memalloc(sizeof(t_printf))))
		return (-1);
	list->format = format;
	list = initialize(list);
	if (format)
	{
		va_start(list->args, format);
		list->len = parse(list);
		va_end(list->args);
	}
	free(list);
	return (list->len);
}
