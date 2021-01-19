/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:24:11 by npimenof          #+#    #+#             */
/*   Updated: 2020/12/03 12:25:40 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int		write_file(int fd, t_file *file)
{
	write(fd, file->data, file->used);
	return (file->used);
}
