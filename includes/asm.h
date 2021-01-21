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
# include <stdbool.h>

# define	FILE_EXT ".s"

/*
typedef enum e_ass_num
{
	T_DIR,
	T_REG,
	T_IND
}			t_ass_num;
*/

typedef struct				s_track
{
	char			*label;
	int				label_start;
	struct s_track	*next;
}							t_track;

typedef struct				s_ass
{
	int						size;
	unsigned char			*statement_buff;
	unsigned char			argument_type;
	int						buff_slot;
	struct	s_ass			*next;
	t_track					*track;
}							t_ass;

typedef struct				s_statement 
{
	char					*opcode;
    unsigned char           opcode;
	char					**arguments;
	bool					arg_type_req;
	int						number_arg;
	int						t_dir;
    char                    *t_dir_jump;
	int						pos;
}							t_statement;

typedef	struct				s_instruction
{
	char					*label;
	t_statement 			*statement;
	struct s_instruction	*next;
}							t_instruction;

typedef struct      s_header
{
    unsigned char   prog_name[5];
    unsigned char   comment[8];
}                   t_header;

#endif
