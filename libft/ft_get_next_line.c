/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:35:41 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/19 17:18:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	trim_line(char **pos, char **line, int fd, int ret)
{
	char	*tmp;
	int		i;

	if (ret < 0)
		return (-1);
	i = 0;
	while (pos[fd][i] && pos[fd][i] != '\n')
		i++;
	if (pos[fd][i] == '\n')
	{
		*line = ft_strsub(pos[fd], 0, i);
		tmp = ft_strdup(pos[fd] + i + 1);
		free(pos[fd]);
		pos[fd] = tmp;
	}
	else if (pos[fd][i] == '\0')
	{
		*line = ft_strsub(pos[fd], 0, i);
		ft_strdel(&pos[fd]);
	}
	return (i + 1);
}

int			ft_get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*pos[FD_MAX];

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!pos[fd])
			pos[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(pos[fd], buf);
			free(pos[fd]);
			pos[fd] = tmp;
		}
		if (ft_strchr(pos[fd], '\n'))
			break ;
	}
	if (ret == 0 && (pos[fd] == NULL || pos[fd][0] == '\0'))
		return (0);
	return (trim_line(pos, line, fd, ret));
}
