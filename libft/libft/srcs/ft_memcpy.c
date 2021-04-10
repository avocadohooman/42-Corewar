/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:34:52 by hopham            #+#    #+#             */
/*   Updated: 2019/10/25 16:45:26 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
** Applications in which dst and src might overlap
** should use memmove(3) instead.
** The memcpy() function returns the original value of (dst).
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	const unsigned char	*str2;

	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (!str && !str2)
		return (0);
	while (n > 0)
	{
		*(str++) = *(str2++);
		n--;
	}
	return (dst);
}
