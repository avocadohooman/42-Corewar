/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:51:26 by orantane          #+#    #+#             */
/*   Updated: 2021/02/03 13:51:12 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include <stdio.h> //remove
# include "error.h"
# include "file.h"
# include <unistd.h>
# include <fcntl.h>

# define MIN_PLAYERS 2

typedef struct  s_player
{
	int				id;
	int				magic;
	char            *file_name;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				exec_size;
	unsigned char	*exec_code;
}               t_player;

typedef struct	s_statement
{
int					bytes_to_next_statement;
unsigned char 		statement;
unsigned char		arg_type;
unsigned char		*arguments;
}				t_statement;

typedef struct	s_carry
{
	int				pos;
	int				cycles_to_execution;
	int				carry_flag;
	int				regs[REG_NUMBER];
	int				last_live;
	t_statement		*statement;
struct s_carry   *next;
}				t_carry;

typedef struct  s_vm
{
	int			dump;
	int			player_nb;
	t_carry		*carries;
	t_player	*players[MAX_PLAYERS + 1];
}               t_vm;

int				get_players(t_vm *vm, char **args, int ac);
int     		read_files(t_vm *vm);
unsigned char			*init_arena(t_vm *vm);

#endif











/*
int val = 2|4;  // = 6

r1 = 1

result = val & 1 = 3

1 != 3 
_________

%1 = 2

result = val & 2 = 2

2 = 2 YEEESSS

*/
