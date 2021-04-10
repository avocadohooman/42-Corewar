/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:52:42 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/16 17:02:22 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		buf;
	int		i;
	int		j;

	len = ft_strlen(dst);
	if (len > dstsize)
		return (dstsize + ft_strlen((char *)src));
	buf = dstsize - len - 1;
	i = 0;
	j = len;
	while (src[i] && i < buf)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen((char *)src));
}
