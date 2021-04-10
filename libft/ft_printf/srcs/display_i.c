/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:46:16 by hopham            #+#    #+#             */
/*   Updated: 2019/12/18 12:13:54 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_num(t_printf *list)
{
	intmax_t	num;

	if (ft_strcmp(list->len_mods_convert, "hh") == 0)
		num = (signed char)va_arg(list->args, int);
	else if (ft_strcmp(list->len_mods_convert, "ll") == 0)
		num = (long long)va_arg(list->args, long long int);
	else if (ft_strcmp(list->len_mods_convert, "h") == 0)
		num = (short)va_arg(list->args, int);
	else if (ft_strcmp(list->len_mods_convert, "l") == 0)
		num = (long)va_arg(list->args, long int);
	else
		num = (int)va_arg(list->args, int);
	return (num);
}

static	int		n_size(intmax_t nb)
{
	int	size;

	if (nb < 0)
		nb = nb * -1;
	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static int		i_and_precision_are_zero(intmax_t i, t_printf *list)
{
	if (i == 0 && list->precision == 0)
	{
		if (list->flag_convert[0] != '-' && list->flag_convert[1] == '+')
			display_gap(list, ' ', list->width - 1, 1);
		else if (list->flag_convert[0] != '-' && list->flag_convert[2] == ' ')
			display_gap(list, ' ', list->width - 1, 1);
		else if (list->flag_convert[0] != '-')
			display_gap(list, ' ', list->width, 1);
		if (list->flag_convert[1] == '+')
			display_exception_char('+', list);
		else if (list->flag_convert[2] == ' ')
			display_exception_char(' ', list);
		if (list->flag_convert[0] == '-' && list->flag_convert[1] == '+')
			display_gap(list, ' ', list->width - 1, 1);
		else if (list->flag_convert[0] == '-' && list->flag_convert[2] == ' ')
			display_gap(list, ' ', list->width - 1, 1);
		else if (list->flag_convert[0] == '-')
			display_gap(list, ' ', list->width, 1);
		return (1);
	}
	return (0);
}

static t_printf	*do_i(t_printf *list, int i_size, intmax_t i)
{
	int		not_blank;
	char	sign;

	not_blank = i_size;
	sign = get_sign(list, (intmax_t)i);
	i *= (i < 0 && i != (-9223372036854775807 - 1)) ? -1 : 1;
	if (i_size <= list->precision)
		not_blank = list->precision;
	if (sign)
		not_blank++;
	list->len += (not_blank <= list->width) ? list->width : not_blank;
	if (list->flag_convert[0] != '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	if (sign)
		write(1, &sign, 1);
	display_gap(list, '0', list->precision - i_size, 0);
	if (i != (-9223372036854775807 - 1))
		ft_putnbr(i);
	else if ((list->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (list->flag_convert[0] == '-')
		display_gap(list, ' ', list->width - not_blank, 0);
	return (list);
}

t_printf		*display_i(t_printf *list)
{
	intmax_t	i;
	int			i_size;

	i = get_num(list);
	if (i_and_precision_are_zero(i, list) == 1)
		return (list);
	i_size = n_size(i);
	if (list->flag_convert[3] == '0' && list->precision == -1 &&
		!list->flag_convert[0])
	{
		list->precision = list->width;
		if (i < 0 || list->flag_convert[1] || list->flag_convert[2])
			list->precision--;
	}
	return (do_i(list, i_size, i));
}
