/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:37:30 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 14:10:32 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lld(t_carriage *carriage)
{
	int	reg_slot;
	int	arg_value;

	reg_slot = carriage->stmt->args[1];
	arg_value = (short)carriage->stmt->args[0] % MEM_SIZE;
}