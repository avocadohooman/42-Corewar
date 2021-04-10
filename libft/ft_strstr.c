/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:55:44 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/17 15:05:06 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = i;
		k = 0;
		while (haystack[j] == needle[k] && haystack[j])
		{
			j++;
			k++;
			if (needle[k] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
