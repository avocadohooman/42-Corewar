/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:51:26 by orantane          #+#    #+#             */
/*   Updated: 2021/04/10 00:38:25 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "libft.h"
# include "error.h"
# include "file.h"
# include "options.h"
# include <stdio.h> //remove
# include <unistd.h>
# include <fcntl.h>
# define MIN_PLAYERS 1
# define OPCODE_AMOUNT 16

typedef struct			s_player
{
	int					id;
	int					magic;
	char				*file_name;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	int					exec_size;
	unsigned char		*exec_code;
}						t_player;

typedef struct			s_stmt
{
	unsigned char		statement;
	unsigned char		arg_type;

	int					arg_types[3];
	int					args[3];
}						t_stmt;

typedef struct			s_carriage
{
	int					abs_pos;
	int					id;
	int					next_statement;
	int					cycles_to_execute;
	int					carry_flag;
	int					regs[REG_NUMBER];
	int					last_live;
	int					cycle;
	t_stmt				*stmt;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_vm
{
	int					player_nb;
	int					carry_nbr;
	int					id_tracker;
	t_player			*last_live;
	t_player			*players[MAX_PLAYERS + 1];
	t_carriage			*carriages;
	int					options[OPT_AMOUNT];
}						t_vm;

typedef struct			s_loop
{
	int					cycle;
	int					nbr_live;
	int					cycle_to_die;
	int					ctd_reset;
	int					nbr_checks;
	int					carry;
	int					tmp_nbr;
	t_carriage			*tmp;
	t_carriage			*head;
	t_carriage			*next;
	t_carriage			*prev;
}						t_loop;

int						parse_args(t_vm *vm, char **args, int ac);
char					**parse_options(t_vm *vm, char **args, int ac);
int						read_files(t_vm *vm);
void					dump_arena(unsigned char *arena);
int						get_player_amount(char **args, int ac);
void					new_player(t_vm *vm, int id, char *name);
int						validate_filename(t_player *player);
unsigned char			*init_arena(t_vm *vm);
void					initiate_carriages(t_vm *vm);
void					battle_loop(t_vm *vm, unsigned char *arena);
void					carriage_loop(t_vm *vm, t_loop *loop,
										unsigned char *arena);
void					init_battle_loop(t_vm *vm, t_loop *loop);
void					execute_statement(t_carriage *carriage, t_vm *vm,
										t_loop *loop, unsigned char *arena);
void					more_execute_statements(t_carriage *carriage, t_vm *vm,
												unsigned char *arena);
void					check_carriages(t_vm *vm, t_loop *loop);
void					cycle_carriages(t_vm *vm, t_loop *loop);
void					kill_carriage(t_carriage *carriage);

int						form_statement(t_carriage *carry,
										unsigned char *arena);
int						get_args(t_carriage *carry, unsigned char *arena,
									int pos);
int						stmt_error(t_carriage *carry, int step);
int						decrypt(t_carriage *carry);
int						convert_4_bytes(unsigned char *data);

t_carriage				*create_carriage(t_vm *vm, t_carriage *next,
										int player_id);

/*
** MEMSPACE GUARDIANS
*/

unsigned char			*fetch_position(unsigned char *arena, int pos,
									int where, int modulo);
int						real_modulo(int position, int value, int modulo);

/*
** OP_HELPER_FUNCTIONS
*/

int						get_arg_value(t_carriage *carriage, int i,
										unsigned char *arena);
int						apply_offset(t_carriage *carriage, int arg_idx_value);
void					write_bytes(unsigned char *arena, int where, int what,
										int size);
int						read_bytes(unsigned char *arena, int where, int size);
void					copy_carriage(t_vm *vm, t_carriage *current);
int						init_stmt(t_carriage *carry, unsigned char *arena);
int						validate_nb(char *str, int player);

/*
** OP_FUNCTIONS
*/

void					op_live(t_carriage *carriage, t_vm *vm);
void					op_ld(t_carriage *carriage, unsigned char *arena);
void					op_st(t_carriage *carriage, unsigned char *arena);
void					op_add(t_carriage *carriage);
void					op_sub(t_carriage *carriage);
void					op_and(t_carriage *carriage, unsigned char *arena);
void					op_or(t_carriage *carriage, unsigned char *arena);
void					op_xor(t_carriage *carriage, unsigned char *arena);
void					op_zjmp(t_carriage *carriage);
void					op_ldi(t_carriage *carriage, unsigned char *arena);
void					op_sti(t_carriage *carriage, unsigned char *arena);
void					op_fork(t_carriage *carriage, t_vm *vm);
void					op_lld(t_carriage *carriage, unsigned char *arena,
							int opt);
void					op_lldi(t_carriage *carriage,
								unsigned char *arena);
void					op_lfork(t_carriage *carriage, t_vm *vm);
void					op_aff(t_carriage *carriage);

#endif
