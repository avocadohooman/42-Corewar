/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:02:48 by seronen           #+#    #+#             */
/*   Updated: 2021/02/07 10:40:15 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_zjmp(t_carriage *carriage)
{
    int     arg_idx_value;

	if (carriage->carry_flag)
    {
        arg_idx_value = carriage->stmt->args[0] % IDX_MOD;
        printf("IDX VALIE: %d\n", carriage->stmt->args[0] % IDX_MOD);
    }
}
