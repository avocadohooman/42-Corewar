/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:30:07 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/12 15:16:59 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		*do_f(t_printf *list, char *nb, char sign)
{
	int	not_blank;

	not_blank = ft_strlen(nb);
	not_blank += sign ? 1 : 0;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-' && list->flag_convert[3] != '0')
		display_gap(list, ' ', list->width - not_blank, 0);
	if (sign)
		write(1, &sign, 1);
	if (list->flag_convert[0] != '-' && list->flag_convert[3] == '0')
		display_gap(list, '0', list->width - not_blank, 0);
	ft_putstr(nb);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	ft_strdel(&nb);
	return (list);
}

t_printf		*display_f(t_printf *list)
{
	char		*nb;
	int			dot;
	long double	num;
	char		sign;

	if (ft_strcmp(list->len_mods_convert, "L") == 0)
		num = va_arg(list->args, long double);
	else
		num = (double)va_arg(list->args, double);
	sign = get_sign(list, num);
	if (list->precision == -1)
		list->precision = 6;
	dot = 0;
	if (list->precision != 0 || list->flag_convert[4] == '#')
		dot = 1;
	if (!(nb = ft_ftoa(num, list->precision, dot)))
		exit(-1);
	return (do_f(list, nb, sign));
}
