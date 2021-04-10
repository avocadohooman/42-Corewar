/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_len_mod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:11:13 by hopham            #+#    #+#             */
/*   Updated: 2019/12/13 15:44:37 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*parse_len_mod(t_printf *list)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (list->len_mods[i])
	{
		while (list->len_mods[i] == list->f_copy[list->i])
		{
			list->len_mods_convert[j] = list->f_copy[list->i];
			list->len_mods_convert[j + 1] = '\0';
			list->i++;
			j++;
		}
		i++;
	}
	return (list);
}
