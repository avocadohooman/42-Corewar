/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:50:54 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/22 18:02:54 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H
# include "asm.h"
# include "ast.h"

void                        encoding_hub(t_ast *ast);
void						get_argument_type(t_ass *ass, t_instruction *instruction);
void						get_arguments(t_ass *ass, t_statement *statement);
int							handle_t_dir_label(t_ass *ass, t_statement *statement, char *t_dir_arg, int t_dir_size);
void						get_component_size(t_ass *ass, t_statement *state, bool write);
unsigned char 				get_statement(char *statement);
int							fetch_jmp(t_track *head, char *key, int from);
void        				track_jmps(t_ass *ass, t_instruction *ins);

#endif
