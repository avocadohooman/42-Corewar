/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:47:32 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/23 17:42:46 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (n <= 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (*a == *b && --n)
	{
		a++;
		b++;
	}
	return (*a - *b);
}
