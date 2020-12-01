/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:11:42 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 15:35:56 by orantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "vm.h"
#include "errors.h"

void	print_error(t_error_type type)
{
	ft_putendl(g_errors[type])
	exit(0);
}
