/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:09:01 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:07:24 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncpy() functions copy at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with `\0' characters.  Otherwise, dst is not terminated.
** function return dst.
*/

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(src + i))
		{
			*(dest + i) = *(src + i);
		}
		else
		{
			while (i < n)
			{
				*(dest + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
