/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:00:15 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/21 20:06:25 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "asm.h"
#include "opcodes.h"
#include <stdio.h> // delete

static void       malloc_instructions(t_instruction *instruction, int amount) 
{
    instruction = (t_instruction *)malloc(sizeof(t_instruction) * amount);
}

static void       assign_arguments(t_ast *compound, t_instruction *instruction)
{
    int i;

    i = 0;
    instruction->statement->arguments = (char **)malloc(sizeof(char *) * instruction->statement->number_arg + 1);
    while (i < instruction->statement->number_arg)
    {
        if (compound->statement_args[i]->arg_type == 1)
            instruction->statement->arguments[i] = ft_strjoin("r", ft_itoa(compound->statement_args[i]->arg_value));
        else if (compound->statement_args[i]->arg_type == 2)
        {
            if (compound->statement_args[i]->label)
                instruction->statement->arguments[i] = ft_strjoin("%:", compound->statement_args[i]->label);
            else 
                instruction->statement->arguments[i] = ft_strjoin("%", ft_itoa(compound->statement_args[i]->arg_value));
        }
        else 
        {
            if (compound->statement_args[i]->label)
                instruction->statement->arguments[i] = ft_strjoin(":", compound->statement_args[i]->label);
            else 
                instruction->statement->arguments[i] = ft_strdup(ft_itoa(compound->statement_args[i]->arg_value));
        }
        i++;
    }
}

void       assign_encoding_data(t_ast *compound, t_instruction *instruction, int label)
{
    if (label == 1) 
    {
        printf("----Instruction Start----\n");
        instruction->label = ft_strdup(compound->label);
    }
    else 
    {
        if (!instruction->label)
            printf("----Instruction Start----\n");
        instruction->statement = (t_statement *)malloc(sizeof(t_statement));
        instruction->statement->number_arg = compound->statement_n_args;
        instruction->statement->component_size = compound->statement_size;
        instruction->statement->opcode = ft_strdup(opcode_table[compound->statement].literal);
        instruction->statement->statement_code = opcode_table[compound->statement].statement_code;
        assign_arguments(compound, instruction);
        printf("number of args: %d\n", instruction->statement->number_arg);
        int i = 0;
        if (instruction->label)
            printf("LABEL: %s  ", instruction->label);
        printf("opcode: %s ", instruction->statement->opcode);
        while (i < instruction->statement->number_arg)
        {
            printf("%s ",instruction->statement->arguments[i]);
            i++;
        }
        printf("\n");
        printf("comp size: %d\n", instruction->statement->component_size);
        printf("statement code: %#.2x\n", instruction->statement->statement_code);
        printf("----Instruction End----\n");
        instruction = instruction->next;
    }
}