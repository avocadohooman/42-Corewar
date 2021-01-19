/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2021/01/19 12:26:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
/*
t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

// This is not used atm :))))))

int		op_table[17] = 
{
	{0x01, {T_DIR}, {0}, {0}, 0, 4},
	{0x02, {T_DIR, T_IND}, {T_REG}, {0}, 1, 4},
	{0x03, {T_REG}, {T_REG, T_IND}, {0}, 1, 4},
	{0x04, {T_REG}, {T_REG}, {T_REG}, 1, 4},
	{0x05, {T_REG}, {T_REG}, {T_REG}, 1, 4},
	{0x06, {T_REG, T_IND, T_DIR}, {T_REG, T_IND, T_DIR}, {T_REG}, 1, 4},
	{0x07, {T_REG, T_IND, T_DIR}, {T_REG, T_IND, T_DIR}, {T_REG}, 1, 4},
	{0x08, {T_REG, T_IND, T_DIR}, {T_REG, T_IND, T_DIR}, {T_REG}, 1, 4},
	{0x09, {T_DIR}, {0}, {0}, 0, 2},
	{0x0a, {T_REG, T_IND, T_DIR}, {T_REG, T_DIR}, {T_REG}, 1, 2},
	{0x0b, {T_REG}, {T_REG, T_IND, T_DIR}, {T_REG, T_DIR}, 1, 2},
	{0x0c, {T_DIR}, {0}, {0}, 0, 2},
	{0x0d, {T_DIR, T_IND}, {T_REG}, {0}, 1, 4},
	{0x0e, {T_REG, T_IND, T_DIR}, {T_REG, T_DIR}, {T_REG}, 1, 2},
	{0x0f, {T_DIR}, {0}, {0}, 0, 2},
	{0x10, {T_DIR}, {0}, {0}, 1, 4},
	{0, {0}, {0}, {0}, 0, 0}
};
*/
// This is used!!!

int		op_table_redefined[17][3] =
{
	{0x01, 0, 4},
	{0x02, 1, 4},
	{0x03, 1, 4},
	{0x04, 1, 4},
	{0x05, 1, 4},
	{0x06, 1, 4},
	{0x07, 1, 4},
	{0x08, 1, 4},
	{0x09, 0, 2},
	{0x0a, 1, 2},
	{0x0b, 1, 2},
	{0x0c, 0, 2},
	{0x0d, 1, 4},
	{0x0e, 1, 2},
	{0x0f, 0, 2},
	{0x10, 1, 4},
	{0, 0, 0}
};
