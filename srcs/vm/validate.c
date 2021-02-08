/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:18:19 by seronen           #+#    #+#             */
/*   Updated: 2021/02/08 21:17:32 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Validate filename
**
**	if filename doesn't end with .cor,
**	throw error and exit immediately!
*/

int		validate_filename(t_player *player)
{
	if (ft_strcmp(&player->file_name[ft_strlen(player->file_name) - 4], ".cor"))
	{
		printf("Invalid player: %s\n", player->file_name);
		printf("DIFF: %s ––VS––– %s\n", &player->file_name[ft_strlen(player->file_name) - 4], ".cor");
		exit(-1);
	}
	return (0);
}