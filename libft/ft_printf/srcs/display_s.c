/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:52:30 by hopham            #+#    #+#             */
/*   Updated: 2019/12/11 10:17:49 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*display_s(t_printf *list)
{
	char	*s;
	int		len;

	s = va_arg(list->args, char *);
	if (!s)
		s = "(null)";
	if (list->precision == -1)
		s = ft_strdup(s);
	else if (list->precision > -1)
		s = ft_strndup(s, list->precision);
	len = ft_strlen(s);
	list->len += len;
	if (list->flag_convert[3] == '0' && list->flag_convert[0] != '-')
		display_gap(list, '0', list->width - len, 1);
	else if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - len, 1);
	ft_putstr(s);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - len, 1);
	ft_strdel(&s);
	return (list);
}
