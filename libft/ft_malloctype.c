/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloctype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:06:31 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/02 14:38:09 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloctype(size_t type, size_t s)
{
	char	*p;

	if (!(p = malloc(sizeof(type) * s)))
		return (NULL);
	ft_bzero(p, type * s);
	return (p);
}
