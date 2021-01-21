/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:08:38 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/21 19:04:48 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h> // delete
#include "encoder.h"

void        encoding_hub(t_ast *root) 
{
	t_instruction 	*instruction;
    t_ass 			ass;
	t_instruction   *tmp;

	visit_ast(root, instruction);
    tmp = instruction;
    // while (tmp)
    // {
    //     if (tmp->label)
    //         printf("label: %s\n", tmp->label);
    //     printf("number of args: %d\n", tmp->statement->number_arg);
    //     int i = 0;
    //     while (i < tmp->statement->number_arg)
    //     {
    //         printf("%s ",tmp->statement->arguments[i]);
    //         i++;
    //     }
    //     ft_putchar('\n');
    //     printf("comp size: %d", tmp->statement->component_size);
    //     printf("opcode: %s\n\n", tmp->statement->opcode);
    //     printf("statement code: %x\n", tmp->statement->statement_code);
    //     tmp = tmp->next;
    // }
}