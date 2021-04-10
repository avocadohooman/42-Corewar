/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:12:36 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 10:21:12 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	i = 0;
	while (s[i] && f)
	{
		newstr[i] = f(s[i]);
		i++;
	}
	return (newstr);
}
