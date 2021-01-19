/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:15:43 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/19 12:15:53 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include "libft.h"

enum
{
	AST_LABEL,
	AST_OPERATION,
	AST_ARGUMENT,
	AST_COMMAND,
	AST_COMPOUND,
	AST_EMPTY
};

typedef struct		s_ast
{
	int				type;
	char			*label;
	int				operation;
	struct s_ast	**operation_args;
	int				arg_type;
	int				arg_value;
	char			*command;
	char			*string;
	struct s_ast	**compound_value;
	int				compound_size;
}					t_ast;

t_ast				*init_ast(int type);
t_ast				*compound_insert(t_ast *compound, t_ast *new);


#endif