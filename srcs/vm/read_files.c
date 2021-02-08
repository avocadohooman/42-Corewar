/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:56 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 20:29:22 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		convert_exec_size(char *data)
{
	int value;

	value = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return (value);
}

int		validate_player(t_player *player)
{
	if (!player->magic)
	{
		printf("No exec magic for player '%s'!\n", player->file_name);
		exit(0);
	}
	if (!player->name[0] || !player->comment[0])
	{
		printf("Failed to fetch name for champion %s!\n", player->name);
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
		player->exec_size = total_size - 2192;						// If exec_size unpresent in bytecode, calculate the exact size yourself
	player->exec_code = malloc(sizeof(char) * player->exec_size + 1);
	bzero(&player->exec_code, sizeof(char) * player->exec_size + 1);
	ft_memcpy(&player->exec_code, &data[2192], player->exec_size);	// index is validated to be 2192! by hackerman
	//printf("hex first index of bcode: %x\n", data[2192]);
	validate_player(player);
	return (0);
}

int     read_files(t_vm *vm)
{
	int i;
	t_file file;

	i = 0;
	while (i < vm->player_nb)
	{
		validate_filename(vm->players[i]);
		file = read_file(vm->players[i]->file_name);
		gather_data(vm->players[i], file.data, file.used);
		i++;
	}
	return (0);
}