/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x16_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:09:13 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 18:04:01 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_aff(t_carriage *carriage)
{
	char	a;

	if (carriage->stmt->arg_types[0] == 1)
	{
		a = (char)carriage->stmt->args[0];
		write(1, &a, 1);
	}
}