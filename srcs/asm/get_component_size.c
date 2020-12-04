/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:01 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/04 15:00:30 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "file.h"
#include <stdio.h> // delete

void			get_component_size(t_ass *ass, char **arguments)
{
	int i;
	int k; 

	i = 1;
	k = 0;    

	ass->size = 0;

	while (arguments[k])
	{
		if (k == 1)
			printf("Arg1: %s\n",ass->arg1 = arguments[k]);
		else if (k == 2)
			printf("Arg2: %s\n",ass->arg2 = arguments[k]);
		else if (k == 3)
			printf("Arg3: %s\n",ass->arg3 = arguments[k]);
		k++;
	}
	while (i < k)
	{
		if (arguments[i][0] == 'r')
			ass->size +=  1;
		else if (arguments[i][0] == '%')
			ass->size +=  2;
		else if (arguments[i][0] == '-')
			ass->size +=  2;
		i++;
		
	}
	//adding statemnt + arg type code
	ass->size += 2;
	ass->statement_buff = (unsigned char*)malloc(sizeof(unsigned char) * ass->size);
	printf("%d\n", ass->size);
}
