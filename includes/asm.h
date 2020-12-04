/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onetane <nen@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:50:53 by orantane          #+#    #+#             */
/*   Updated: 2020/12/01 15:26:51 by onen              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/uio.h>
# include <sys/types.h>
# include "libft.h"
# include "op.h"
# include <stdio.h> // delete

# define	FILE_EXT ".s"


typedef enum e_ass_num
{
	T_DIR,
	T_REG,
	T_IND
}			t_ass_num;

typedef struct	s_ass
{
	int						arg1_type;
	int						arg2_type;
	int						arg3_type;
	int						size;
	unsigned char			*statement_buff;
}				t_ass;

typedef struct	s_statement 
{
	char	*opcode;
	char	*arg1;
	char	*arg2;
	char	*arg3;
}				t_statement;

typedef	struct	s_instruction
{
	char		*label;
	t_statement *statement;
}				t_instruction;


void			get_argument_type(t_ass *ass, char **arguments);
void			get_arguments(t_ass *ass);
void 			get_component_size(t_ass *ass, char **arguments);
int 			get_statement(char *statement);

#endif
