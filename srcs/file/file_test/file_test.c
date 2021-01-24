/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:56:29 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/24 22:50:15 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "file.h"

int		test_new_file(void)
{
	t_file	file;
	int		size;
	int		sum;
	int		i;

	size = 512;
	new_file(&file, size);
	if (file.size != size)
		return (0);
	sum = 0;
	i = -1;
	while (++i < file.size)
		sum += file.data[i];
	if (sum)
		return (0);
	return (1);
}

int		test_insert_file(void)
{
	t_file	file;
	int		size;
	char	*data = "hello world";
	int		data_size;

	size = 1;
	data_size = ft_strlen(data);
	new_file(&file, size);
	insert_file(&file, data, data_size);
	if (file.used != data_size)
		return (0);
	if (ft_memcmp(file.data, data, file.used))
		return (0);
	return (1);
}

int		main(void)
{
	if (!test_new_file())
	{
		printf("test_new_file: [ FAILED ]\n");
		return (1);
	}
	if (!test_insert_file())
	{
		printf("test_insert_file: [ FAILED ]\n");
		return (1);
	}
	return (0);
}
