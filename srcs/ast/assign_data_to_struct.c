/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:00:15 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/23 12:36:54 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "opcodes.h"
#include <stdio.h> // delete

char       *assign_arguments(t_ast *arg)
{
    if (arg->arg_type == 1)
        return (ft_strjoin("r", ft_itoa(arg->arg_value)));
    else if (arg->arg_type == 2)
    {
        if (arg->label)
            return (ft_strjoin("%:", arg->label));
        else 
            return (ft_strjoin("%", ft_itoa(arg->arg_value)));
    }
    else 
    {
        if (arg->label)
            return (ft_strjoin(":", arg->label));
        else 
            return (ft_strdup(ft_itoa(arg->arg_value)));
    }
}

