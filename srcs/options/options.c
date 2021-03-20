/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:53:10 by seronen           #+#    #+#             */
/*   Updated: 2021/03/20 03:01:18 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

int32_t		toggle_option(int32_t opts, int which)
{
	return (opts ^= 1UL << which);
}

int		read_option(int32_t opts, int which)
{
	return (((opts >> which) & 1U) == 0 ? 0 : 1);
}
