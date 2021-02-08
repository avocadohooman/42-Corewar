/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: orantane <orantane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:51:26 by orantane          #+#    #+#             */
/*   Updated: 2021/02/08 14:09:04 by orantane         ###   ########.fr       */
=======
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:51:26 by orantane          #+#    #+#             */
/*   Updated: 2021/02/07 10:42:17 by Gerhard          ###   ########.fr       */
>>>>>>> master
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

typedef struct  s_stmt
{
	unsigned char	statement;
	unsigned char	arg_type;

	int				arg_types[3];
	int				args[3];
}               t_stmt;

typedef struct  s_carriage 
{
	unsigned char		*pos;
	int					cycle;
	int                 cycles_to_execute;
	int                 carry_flag;
	int                 regs[REG_NUMBER];
	int                 last_live;
	int					cycle;
	t_stmt     			*stmt;
	struct s_carriage  *next;
}               t_carriage;

typedef struct  s_vm
{
	int			dump;
	int			player_nb;
	int			carry_nbr;
	t_player	*players[MAX_PLAYERS + 1];
    t_carriage  *carriages;
}               t_vm;

typedef struct	s_loop
{
	int			cycle;
	int			nbr_live;
	int			cycle_to_die;
	int			ctd_reset;
	int			nbr_checks;
	t_carriage	*head;
}				t_loop;



int					get_players(t_vm *vm, char **args, int ac);
int					read_files(t_vm *vm);
unsigned char       *init_arena(t_vm *vm);
void				initiate_carriages(t_vm *vm, unsigned char *arena);
int     			form_statement(t_carriage *carry);
<<<<<<< HEAD
void				battle_loop(t_vm *vm, unsigned char *arena);
=======
int					convert_4_bytes(unsigned char *data);

/** OP_HELPER_FUNCTIONS **/

int      			get_arg_value(t_carriage *carriage, int arg_value, int i);

/** OP_FUNCTIONS **/

void				op_live(t_carriage *carriage, t_vm *vm);
void				op_ld(t_carriage *carriage);
void				op_st(t_carriage *carriage);
void				op_add(t_carriage *carriage);
void				op_sub(t_carriage *carriage);
void				op_and(t_carriage *carriage);
void				op_or(t_carriage *carriage);
void				op_xor(t_carriage *carriage);
void    			op_zjmp(t_carriage *carriage);


>>>>>>> master

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
