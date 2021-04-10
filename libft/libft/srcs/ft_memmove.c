/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:17:48 by hopham            #+#    #+#             */
/*   Updated: 2019/10/22 12:55:11 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap;
** the copy is always done in a non-destructive manner.
** The memmove() function returns the original value of (dst).
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*str;
	const unsigned char		*str2;
	size_t					i;

	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (!str && !str2)
		return (NULL);
	i = 0;
	if (str2 < str)
		while (++i <= len)
		{
			str[len - i] = str2[len - i];
		}
	else
		while (len-- > 0)
		{
			*(str++) = *(str2++);
		}
	return (dst);
}
