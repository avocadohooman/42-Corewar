/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:36:40 by npimenof          #+#    #+#             */
/*   Updated: 2021/02/03 10:42:40 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

static const char *g_parser_error[] = {
	[ERROR_UNKNOWN_COMMAND] = "Unknown command.",
	[ERROR_UNEXPECTED_ARG_TYPE] = "Unexpected argument type.",
	[ERROR_MALFORMATTED_ARG] = "Malformatted argument",
	[ERROR_UNKNOWN_STATEMENT] = "Unknown operation."
};

void    parser_exit_with_message(t_parser_error type)
{
    ft_putendl_fd(g_parser_error[type], 2);
    exit(1);
}
