/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:28:08 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/02 19:42:02 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	char *sc1;

	if (!s1)
		return (0);
	sc1 = (char *)s1;
	while (*sc1)
	{
		if (ft_strchr(s2, *sc1))
			return (sc1 - (char *)s1);
		sc1++;
	}
	return (sc1 - (char *)s1);
}
