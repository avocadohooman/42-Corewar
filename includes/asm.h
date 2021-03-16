/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:54:25 by npimenof          #+#    #+#             */
/*   Updated: 2021/03/16 19:18:07 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <sys/uio.h>
# include <sys/types.h>
# include "libft.h"
# include "op.h"
# include <stdbool.h>

# define FILE_EXT ".s"

typedef struct				s_track
{
	char					*label;
	int						label_start;
	struct s_track			*next;
}							t_track;

typedef struct				s_ass
{
	int						size;
	unsigned char			*statement_buff;
	unsigned char			argument_type;
	int						buff_slot;
	struct s_ass			*next;
	t_track					*track;
}							t_ass;

typedef struct				s_statement
{
	char					*opcode;
	unsigned char			statement_code;
	char					**arguments;
	bool					arg_type_req;
	int						number_arg;
	int						t_dir;
	int						pos;
	int						component_size;
}							t_statement;

typedef	struct				s_instruction
{
	char					*label;
	t_statement				*statement;
	struct s_instruction	*next;
}							t_instruction;

typedef struct				s_header
{
	unsigned char			prog_name[5];
	unsigned char			comment[8];
}							t_header;

#endif
