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

typedef struct		s_ast
{
	int				type;
	char			*label;
	int				operation;
	t_ast			**operations_args;
	int				arg_value;
}					t_ast;
