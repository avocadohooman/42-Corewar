/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:56 by seronen           #+#    #+#             */
/*   Updated: 2021/01/14 22:49:15 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		convert_exec_size(char *data)
{
	uint32_t value;

	value = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	if (value > CHAMP_MAX_SIZE)
	{
		printf("Exec code size over limit!\n");
		exit(0);
	}
	if (!value)
		value = CHAMP_MAX_SIZE;
	return (value);
}

int		gather_data(t_player *player, char *data)
{
	if (!data || !player)
	{
		printf("No data or player!\n");
		exit(-42);
	}
	ft_memcpy(&player->name, &data[4], 128);
	ft_memcpy(&player->comment, &data[140], 2048);
	if (!player->name[0] || !player->comment[0])
	{
		printf("Failed to fetch name for champion %s!\n", player->name);
		exit(0);
	}
	player->exec_size = convert_exec_size(&data[136]);
	player->exec_code = malloc(sizeof(char) * player->exec_size + 1);
	bzero(&player->exec_code, sizeof(char) * player->exec_size + 1);
	ft_memcpy(&player->exec_code, &data[2192], player->exec_size);	// index is validated to be 2192! by hackerman
	//printf("hex first index of bcode: %x\n", data[2192]);
	return (0);
}

int     read_files(t_vm *vm)
{
	int i;
	t_file file;
	int fd;
	int exec_size;

	i = 0;
	while (i < vm->player_nb)
	{
		file = read_file(vm->players[i]->file_name);
		gather_data(vm->players[i], file.data);
		printf("Found name: %s\n", vm->players[i]->name);
		printf("Found comment: %s\n", vm->players[i]->comment);
		printf("Found exec code size: %d\n", vm->players[i]->exec_size);
		i++;
	}
	return (0);
}