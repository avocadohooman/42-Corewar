/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:32:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/26 16:25:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	char	*sc1;

	sc1 = (char *)s1;
	while (*sc1)
	{
		if (!ft_strchr(s2, *sc1))
			return (sc1 - (char *)s1);
		sc1++;
	}
	return (sc1 - (char *)s1);
}
