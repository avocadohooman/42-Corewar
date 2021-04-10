/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:56:43 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:06:14 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcpy() functions copy the string src to dst
** (including the terminating `\0' character.)
** function return dst
*/

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
