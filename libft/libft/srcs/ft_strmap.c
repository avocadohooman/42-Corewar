/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:35:38 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:26:04 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*str2;
	int		i;

	str2 = (char*)s;
	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char*)malloc((size_t)(ft_strlen((char*)s) + 1));
	if (!str)
		return (NULL);
	while (str2[i])
	{
		str[i] = f(str2[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
