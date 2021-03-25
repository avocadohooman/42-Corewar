/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:56 by seronen           #+#    #+#             */
/*   Updated: 2021/03/16 18:51:16 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		convert_exec_size(char *data)
{
	int				value;
	unsigned char	*d;

	d = (unsigned char*)data;
	value = (d[0] << 24) | (d[1] << 16) | (d[2] << 8) | d[3];
	return (value);
}

int		validate_player(t_player *player)
{
	if (!player->magic)
	{
		printf("No exec magic for player '%s'!\n", player->file_name);
		exit(0);
	}
	if (player->exec_size > CHAMP_MAX_SIZE)
	{
		printf("Exec code size over limit for player '%s'!\n", player->name);
		exit(0);
	}
	return (0);
}

int		gather_data(t_player *player, char *data, size_t total_size)
{
	if (!data || !player)
	{
		printf("No data or player!\n");
		exit(-42);
	}
	player->magic = convert_exec_size(&data[0]);
	ft_memcpy(&player->name, &data[4], 128);
	ft_memcpy(&player->comment, &data[140], 2048);
	player->exec_size = convert_exec_size(&data[136]);
	if (!player->exec_size)
		player->exec_size = total_size - 2192;
	player->exec_code = malloc(sizeof(char) * player->exec_size + 1);
	bzero(player->exec_code, sizeof(char) * player->exec_size + 1);
	ft_memcpy(player->exec_code, &data[2192], player->exec_size);
	validate_player(player);
	return (0);
}

int		read_files(t_vm *vm)
{
	int		i;
	t_buf	file;

	i = 0;
	while (i < vm->player_nb)
	{
		if (!file_extension(vm->players[i]->file_name, ".cor"))
		{
			printf("Unsupported file extension for player: %s!\n",
				vm->players[i]->file_name);
			exit(0);
		}
		file = buf_read(vm->players[i]->file_name);
		gather_data(vm->players[i], file.data, file.used);
		free(file.data);
		i++;
	}
	return (0);
}
