/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:02:04 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/12 11:20:32 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	get_num(t_printf *list)
{
	uintmax_t	num;

	if (ft_strcmp(list->len_mods_convert, "hh") == 0)
		num = (unsigned char)va_arg(list->args, unsigned int);
	else if (ft_strcmp(list->len_mods_convert, "ll") == 0)
		num = (unsigned long long)va_arg(list->args, unsigned long long int);
	else if (ft_strcmp(list->len_mods_convert, "h") == 0)
		num = (unsigned short)va_arg(list->args, unsigned int);
	else if (ft_strcmp(list->len_mods_convert, "l") == 0)
		num = (unsigned long)va_arg(list->args, unsigned long int);
	else
		num = (unsigned int)va_arg(list->args, unsigned int);
	return (num);
}

t_printf			*print_options(t_printf *list, char *str, uintmax_t num)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (list->flag_convert[4] == '#' && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= list->precision)
		not_blank = list->precision;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	if (list->flag_convert[4] == '#' && num)
		write(1, "0", 1);
	display_gap(list, '0', list->precision - num_width, 0);
	ft_putstr(str);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	ft_strdel(&str);
	return (list);
}

t_printf			*display_o(t_printf *list)
{
	char		*str;
	uintmax_t	num;

	num = get_num(list);
	if (num == 0 && list->precision == 0 && list->flag_convert[4] != '#')
	{
		display_gap(list, ' ', list->width, 1);
		return (list);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (list->flag_convert[3] == '0' && list->precision == -1 &&
		!list->flag_convert[0])
		list->precision = list->width;
	return (print_options(list, str, num));
}
