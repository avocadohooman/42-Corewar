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

# include "parser.h"
 
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
    void        (*parse)(t_parser*);
}               t_opcode;

static t_opcode opcode_table[] = {
    {LFORK_LITERAL, parser_parse_lfork},
    {STI_LITERAL, parser_parse_sti},
    {FORK_LITERAL, parser_parse_fork},
    {LLD_LITERAL, parser_parse_lld},
    {LD_LITERAL, parser_parse_ld},
    {ADD_LITERAL, parser_parse_add},
    {ZJMP_LITERAL, parser_parse_zjmp},
    {SUB_LITERAL, parser_parse_sub},
    {LDI_LITERAL, parser_parse_ldi},
    {OR_LITERAL, parser_parse_or},
    {ST_LITERAL, parser_parse_st},
    {AFF_LITERAL, parser_parse_aff},
    {LIVE_LITERAL, parser_parse_live},
    {XOR_LITERAL, parser_parse_xor},
    {LLDI_LITERAL, parser_parse_lldi},
    {AND_LITERAL, parser_parse_and},
    {NULL, NULL},
};

int     lookup_opcode(char *str);
void    opcode_parse(t_parser *parser);

#endif