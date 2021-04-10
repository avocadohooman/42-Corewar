/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:11:50 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/13 14:17:28 by hopham           ###   ########.fr       */
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

static void			print_leading_zero(uintmax_t num, char hash, char x)
{
	if (num && hash == '#')
	{
		if (x == 'x')
			write(1, "0x", 2);
		if (x == 'X')
			write(1, "0X", 2);
	}
}

static t_printf		*do_x(t_printf *list, char *str, uintmax_t num, int i)
{
	int			num_width;
	int			not_blank;

	num_width = ft_strlen(str);
	if (list->flag_convert[4] == '#' && list->flag_convert[3] == '0'
		&& list->width && i == -1 && num)
		num_width += 2;
	else if (list->flag_convert[4] == '#' && num)
	{
		list->width -= 2;
		list->len += 2;
	}
	not_blank = (num_width <= list->precision && list->precision > 0)
				? list->precision : num_width;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	print_leading_zero(num, list->flag_convert[4], list->specifier_char);
	display_gap(list, '0', list->precision - num_width, 0);
	ft_putstr(str);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	ft_strdel(&str);
	return (list);
}

t_printf			*display_x(t_printf *list)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			i;

	num = get_num(list);
	if (num == 0 && list->precision == 0)
	{
		display_gap(list, ' ', list->width, 1);
		return (list);
	}
	c = 'a';
	if (list->specifier_char == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	i = list->precision;
	if (list->flag_convert[3] == '0' && list->precision == -1
		&& !list->flag_convert[0])
		list->precision = list->width;
	return (do_x(list, str, num, i));
}
