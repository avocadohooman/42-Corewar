/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:21:19 by gmolin            #+#    #+#             */
/*   Updated: 2021/03/24 11:29:13 by Gerhard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "libft.h"
# include "asm.h"
# include "label.h"
# include "file.h"
# include "stdio.h" //remove

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
	t_label			*label_list;
	int				label_index;
	char			statement;
	int				statement_position;
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
	int				body_byte_size;

	struct s_ast	**instruction_value;
	int				instruction_size;

	struct s_ast	**compound_value;
	int				compound_size;
}					t_ast;

t_ast				*init_ast(int type);
t_ast				*compound_insert(t_ast *compound, t_ast *new);
t_buf				*visit_compound(t_ast *compound);
t_buf				*visit_header(t_ast *header);
t_buf				*visit_body(t_ast *body);
char				*visit_label(t_ast *label);
t_statement			*visit_statement(t_ast *statement);
t_buf				*visit_instruction(t_ast *instruction);
t_buf				*visit_ast(t_ast *ast);
t_buf				*encode_statement(t_ast *stmt);
char				*assign_arguments(t_ast *arg);

#endif
