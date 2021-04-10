/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:37:12 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 18:27:30 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strnstr() function locates the first occurrence of the null-terminated string
** src in the string dst, where not more than len characters are searched.
** If src is an empty string, dst is returned; if src occurs nowhere in
** haystack, NULL is returned; otherwise a pointer to the first character
** of the first occurrence of src is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!*src)
		return ((char*)dest);
	while (dest[i] != '\0' && i < len)
	{
		if (src[0] == dest[i])
		{
			size = 1;
			while (dest[i + size] == src[size] && i + size < len
			&& src[size] != '\0')
				size++;
			if (src[size] == '\0')
				return ((char*)&dest[i]);
		}
		i++;
	}
	return (0);
}
