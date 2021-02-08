/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:19:11 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/07 12:28:51 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int         apply_offset(t_carriage *carriage, int arg_idx_value)
{
    if (arg_idx_value >= 0) 
        arg_idx_value -= carriage->offset;
    else
        arg_idx_value += carriage->offset;
    return (arg_idx_value);
}