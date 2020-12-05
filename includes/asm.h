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
	int				labelnb;
	int				jmp_bytes;
	struct s_track	*next;
}							t_track;

typedef struct				s_ass
{
	int						size;
	unsigned char			*statement_buff;
	unsigned char			argument_type;
	t_track					*track;
}							t_ass;

typedef struct				s_statement 
{
	char					*opcode;
	char					**arguments;
	bool					arg_type_req;
	int						number_arg;
	int						t_dir;
}							t_statement;

typedef	struct				s_instruction
{
	char					*label;
	t_statement 			*statement;
	struct s_instruction	*next;
}							t_instruction;

void			get_argument_type(t_ass *ass, t_instruction *instruction);
void			get_arguments(t_ass *ass, t_instruction *instruction);
int				get_component_size(t_ass *ass, t_statement *state);
unsigned char 	get_statement(char *statement);
int				fetch_jmp(t_track *head, char *key);
void        	track_jmps(t_ass *ass, t_instruction *ins);

#endif
