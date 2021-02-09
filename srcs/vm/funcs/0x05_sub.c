/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x05_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:14 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/09 00:50:44 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_sub(t_carriage *carriage)
{
	int     sum;

	sum = carriage->regs[carriage->stmt->args[0]];
	sum -= carriage->regs[carriage->stmt->args[1]];
	carriage->regs[carriage->stmt->args[2]] = sum;
	if (sum == 0)
		carriage->carry_flag = 1;
	else 
		carriage->carry_flag = 0;
}