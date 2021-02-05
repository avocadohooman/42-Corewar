/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:26:34 by seronen           #+#    #+#             */
/*   Updated: 2021/02/05 15:49:04 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    live(t_carriage *carriage, unsigned char *arena)
{
    if (!carriage->carry_flag)
    {
        printf("Hello!\n");
    }
}