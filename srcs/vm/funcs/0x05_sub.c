/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:48:14 by Gerhard           #+#    #+#             */
/*   Updated: 2021/02/05 15:50:36 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    sub(t_carriage *carriage, unsigned char *arena)
{
    if (!carriage->carry_flag)
    {
        printf("Hello!\n");
    }
}