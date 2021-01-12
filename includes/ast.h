/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:43:24 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/12 13:45:42 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum {
    OPCODE
};

typedef struct  s_ast
{
    int         type;
    char        *opcode;
    char        **args;
    char        *command;
    char        *command_string;
}               t_ast;
