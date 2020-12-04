/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:19:49 by gmolin            #+#    #+#             */
/*   Updated: 2020/12/03 16:24:100 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>
#include <stdlib.h>
#include <string.h>
#include "libft/includes/libft.h"

typedef enum e_ass_num
{
	T_DIR,
	T_REG,
	T_IND
}			t_ass_num;

typedef struct	s_ass
{
	char					**label;
	char					*operation; // = sti = 0x0b
	int						operation_index;
	int						arg1_type;
	int						arg2_type;
	int						arg3_type;
	char					*arg1;
	char					*arg2;
	char					*arg3;
	unsigned char			argument_type_code;
	int						size;
	unsigned char			*statement_buff;
}				t_ass;


static void 	get_component_size(t_ass *ass, char **arguments)
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

static int 		get_statement(char *statement)
{
	if (!ft_strcmp("sti", statement))
		return 0x0b;
	else if (!ft_strcmp("ld", statement))
		return 0x02;
	else
		return NULL;
}

static void		get_argument_type(t_ass *ass, char **arguments)
{
	if (!ft_strcmp("sti", arguments[0]))
		ass->argument_type_code = 0x68;
	else if (!ft_strcmp("ld", arguments[0])) 
		ass->argument_type_code = 0x90;

}

static void		get_arguments(t_ass *ass)
{

	// 0x0b 0x68 0x01 0x00 0x07 0x00 0x01
	
}	
	
int main()
{
	int 	i = 42;
	char 	*line = "sti r1, %:live, %1";
	char 	**arguments;
	t_ass 	ass;
	unsigned char	*buff;

	buff = (unsigned char*)malloc(sizeof(unsigned char) * 7);
	buff[0] = 0x00;
	buff[1] = 0x68;
	buff[2] = 0x01;
	buff[3] = 0x00;
	buff[4] = 0x07;
	buff[5] = 0x00;
	buff[6] = 0x01;

	// arguments = ft_strsplit(line, ' ');

	// get_component_size(&ass, arguments);
	// printf("Statement code: %d\n", get_statement(arguments[0]));
	// get_argument_type(&ass, arguments);
	int fd = open("bytecode", O_RDWR, 0777);

	write(fd, buff, 7);
	close(fd);
}	
