/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:56 by seronen           #+#    #+#             */
/*   Updated: 2021/01/14 16:40:21 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*ft_force_strndup(char *str, int bytes)
{
	int i;
	char *new;
	
	new = malloc(sizeof(char) * bytes + 1);
	i = 0;
	while (i < bytes)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

int		get_exec_code(char *buf)
{
	
	return (0);
}

int		gather_data(t_vm *vm, char *buf)
{
	write(1, &buf[4], 8);
	write(1, &buf[110], 110);
	return (0);
}

int     read_files(t_vm *vm)
{
	int i;
	t_file file;
	int fd;
	int exec_size;
	char buf[500];
	bzero(buf, 500);

	i = 0;
	while (i < vm->player_nb)
	{
		fd = open(vm->players[i]->file_name, O_RDONLY);
		read(fd, buf, 400);
		write(1, &buf[4], 8);
		printf("\n");
		write(1, &buf[110], 110);
		printf("\n");
		printf("size: %x\n", buf[106]);
		printf("\n");
		i++;
	}
	return (0);
}