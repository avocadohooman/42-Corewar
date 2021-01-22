/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:08:38 by gmolin            #+#    #+#             */
/*   Updated: 2021/01/22 22:35:18 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <stdio.h> // delete
#include "encoder.h"

void        encoding_hub(t_instruction *instruction) 
{
    t_ass 			ass;
    t_instruction   *tmp;
    int i = 0;

	ass.track = 0;
	tmp = instruction;
	ass.buff_slot = 0;
	int fd = open("bytecode", O_RDWR, 0777);
	track_jmps(&ass, instruction);
	while (tmp)
	{
        if (tmp->statement)
        {
            write_component_size(&ass, tmp->statement);
            get_argument_type(&ass, tmp);
            printf("\nInstruction ByteCode: \n");
            get_arguments(&ass, tmp->statement);
            i = 0;
            while (i < ass.buff_slot)
            {
                printf("%.2x ", ass.statement_buff[i]);
                i++;
            }
            printf("\n------\n\n");
            ass.buff_slot = 0;
            write(fd, ass.statement_buff, ass.size);
        }
		tmp = tmp->next;
	}
	close(fd);
    return ;
}