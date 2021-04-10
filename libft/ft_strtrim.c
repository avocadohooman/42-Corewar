/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:30:57 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 10:29:52 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	while (ft_iswhitespace(s[i]) || ft_iswhitespace(s[j]))
	{
		if (ft_iswhitespace(s[i]))
			i++;
		if (ft_iswhitespace(s[j]))
			j--;
		if (i > j)
			break ;
	}
	if (!(newstr = ft_strnew(j + 1 - i)))
		return (NULL);
	k = 0;
	while (i <= j)
		newstr[k++] = s[i++];
	return (newstr);
}
