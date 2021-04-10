/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:23:25 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 10:22:11 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	i = 0;
	while (s[i] && f)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
