/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:31:31 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 10:54:31 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	if (dst == src)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (b < a)
		while (len--)
			a[len] = b[len];
	else
		while (len--)
			*a++ = *b++;
	return (dst);
}
