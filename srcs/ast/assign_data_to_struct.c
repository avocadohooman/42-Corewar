/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:00:15 by gmolin            #+#    #+#             */
/*   Updated: 2021/03/24 11:32:16 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "opcodes.h"

char	*assign_arguments(t_ast *arg)
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
