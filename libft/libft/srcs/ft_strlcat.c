/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:06:31 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:24:04 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strlcat() appends string src to the end of dst.
** It will append at most dstsize - strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the
** original dst string was longer than dstsize
** (in practice this should not happen as it means that
** either dstsize is incorrect or that dst is not a proper string).
** functions return the total length of the string they tried to create,
** means the initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = ft_strlen(dst);
	j = ft_strlen((char*)src);
	if (dstsize <= i)
		a = dstsize + j;
	else
		a = j + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (a);
}
