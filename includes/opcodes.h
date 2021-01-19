/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:37:07 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/03 09:47:39 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPCODES_H
# define OPCODES_H

# include "op.h"
# include "parser.h"
# include "ast.h"
 
# define LFORK_LITERAL	"lfork"
# define STI_LITERAL	"sti"
# define FORK_LITERAL	"fork"
# define LLD_LITERAL	"lld"
# define LD_LITERAL		"ld"
# define ADD_LITERAL	"add"
# define ZJMP_LITERAL	"zjmp"
# define SUB_LITERAL	"sub"
# define LDI_LITERAL	"ldi"
# define OR_LITERAL		"or"
# define ST_LITERAL		"st"
# define AFF_LITERAL	"aff"
# define LIVE_LITERAL	"live"
# define XOR_LITERAL	"xor"
# define LLDI_LITERAL	"lldi"
# define AND_LITERAL	"and"

typedef struct  s_opcode
{
    char        *literal;
    int         argument_amount;
    int         argument_types[3];
    void        (*parse)(t_parser*);
}               t_opcode;

enum {
    LIVE_INDEX,
    LD_INDEX,
    ST_INDEX,
    ADD_INDEX,
    SUB_INDEX,
    AND_INDEX,
    OR_INDEX,
    XOR_INDEX,
    ZJMP_INDEX,
    LDI_INDEX,
    STI_INDEX,
    FORK_INDEX,
    LLD_INDEX,
    LLDI_INDEX,
    LFORK_INDEX,
    AFF_INDEX,
    NO_OPERATION
};

static const t_opcode opcode_table[] = {

	[LFORK_INDEX] = {LFORK_LITERAL, 1, {T_DIR}, NULL},
	[STI_INDEX] = {STI_LITERAL, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, NULL},
	[FORK_INDEX] = {FORK_LITERAL, 1, {T_DIR}, NULL},
	[LLD_INDEX] = {LLD_LITERAL, 2, {T_DIR | T_IND, T_REG}, NULL},
	[LD_INDEX] = {LD_LITERAL, 2, {T_DIR | T_IND, T_REG}, NULL},
	[ADD_INDEX] = {ADD_LITERAL, 3, {T_REG, T_REG, T_REG}, NULL},
	[ZJMP_INDEX] = {ZJMP_LITERAL, 1, {T_DIR}, NULL},
	[SUB_INDEX] = {SUB_LITERAL, 3, {T_REG, T_REG, T_REG}, NULL},
	[LDI_INDEX] = {LDI_LITERAL, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, NULL},
	[OR_INDEX] = {OR_LITERAL, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, NULL},
	[ST_INDEX] = {ST_LITERAL, 2, {T_REG, T_IND | T_REG}, NULL},
	[AFF_INDEX] = {AFF_LITERAL, 1, {T_REG}, NULL},
    [LIVE_INDEX] = {LIVE_LITERAL, 1, {T_DIR}, NULL},
	[XOR_INDEX] = {XOR_LITERAL, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, NULL},
	[LLDI_INDEX] = {LLDI_LITERAL, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, NULL},
	[AND_INDEX] = {AND_LITERAL, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, NULL},
	[NO_OPERATION] = {0, 0, 0, 0}
};

int		lookup_opcode(char *str);
t_ast	*opcode_parse(t_parser *parser);
int		check_argument(int options, int received);

#endif
