/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:43:24 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/13 16:05:14 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include "libft.h"

enum
{
	AST_LABEL,
	AST_STATEMENT,
	AST_ARGUMENT,
	AST_COMMAND,
	AST_COMPOUND,
	AST_HEADER,
	AST_BODY,
	AST_INSTRUCTION,
	AST_EMPTY
};

typedef struct		s_ast
{
	int				type;
	char			*label;
	int				label_index;
	int				statement;
	int				statement_n_args;
	struct s_ast	**statement_args;
	int				arg_size;
	int				statement_size;
	int				arg_type;
	int				arg_value;
	char			*command;
	char			*string;

	struct s_ast	**header_value;
	int				header_size;

	struct s_ast	**body_value;
	int				body_size;

	struct s_ast	**instruction_value;
	int				instruction_size;	

	struct s_ast	**compound_value;
	int				compound_size;
}					t_ast;

t_ast				*init_ast(int type);
t_ast				*compound_insert(t_ast *compound, t_ast *new);

void				visit_ast(t_ast *ast);


#endif
