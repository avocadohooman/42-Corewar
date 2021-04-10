/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:39:15 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:52:11 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strstr() function locates the first occurrence of the null-terminated string
** src in the null-terminated string dst.
** If src is an empty string, dst is returned; if src occurs nowhere in
** dst, NULL is returned;otherwise a pointer to the first character of the first
** occurrence of src is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *dest, const char *src)
{
	int	i;
	int	size;

	i = 0;
	if (src[0] == '\0')
		return ((char*)dest);
	while (dest[i] != '\0')
	{
		if (src[0] == dest[i])
		{
			size = 1;
			while (dest[i + size] == src[size] && src[size] != '\0')
				size++;
			if (src[size] == '\0')
				return ((char*)&dest[i]);
		}
		i++;
	}
	return (0);
}
