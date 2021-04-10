/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:52:24 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/04 13:30:05 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1);
	if (!(newstr = ft_strnew(len + ft_strlen((char *)s2))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[i + 1] || s2[j + 1])
	{
		if (s1[i + 1] && ++i > -1)
			newstr[i] = s1[i];
		if (s2[j + 1] && ++j > -1)
			newstr[len + j] = s2[j];
	}
	return (newstr);
}
