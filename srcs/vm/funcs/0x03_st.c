/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:06 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/05 15:33:23 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    op_st(t_carriage *carriage, t_vm *vm, unsigned char *arena)
{
    if (!carriage->carry_flag)
    {
        printf("Hello!\n");
    }
}