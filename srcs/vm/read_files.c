/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gerhard <Gerhard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:23:56 by seronen           #+#    #+#             */
/*   Updated: 2021/04/20 10:24:30 by Gerhard          ###   ########.fr       */
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
		print_error(INVALID_ARG);
	if (player->exec_size > CHAMP_MAX_SIZE)
		print_error(INVALID_ARG);
	return (0);
}

int		validate_exec_code_size(int size, int total_size)
{
	if (!size)
	{
		size = total_size - 2192;
		if (size < 1)
			return (1);
		return (0);
	}
	if (size != total_size - 2192)
		return (1);
	return (0);
}

int		gather_data(t_player *player, char *data, size_t total_size)
{
	if (!data || !player)
		print_error(MALLOC);
	player->magic = convert_exec_size(&data[0]);
	ft_strncpy(player->name, &data[4], 128);
	ft_strncpy(player->comment, &data[140], 2048);
	player->exec_size = convert_exec_size(&data[136]);
	// if (validate_exec_code_size(player->exec_size, total_size))
	// 	print_error(INVALID_ARG);
	total_size += 1;
	total_size -= 1;
	player->exec_code = ft_memalloc(sizeof(char) * player->exec_size + 1);
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
			print_error(INVALID_ARG);
		file = buf_read(vm->players[i]->file_name);
		gather_data(vm->players[i], file.data, file.used);
		free(file.data);
		i++;
	}
	return (0);
}
