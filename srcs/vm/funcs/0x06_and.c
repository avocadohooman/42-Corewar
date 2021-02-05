/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x06_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:17 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/05 15:33:19 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_and(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
    if (!carriage->carry_flag)
    {
        printf("Hello!\n");
    }
}