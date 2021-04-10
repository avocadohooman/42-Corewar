/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:42:33 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/21 19:04:04 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!(newstr = ft_strnew(len)) || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
