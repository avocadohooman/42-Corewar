/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:23:13 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 10:47:08 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’.
** If s has no whitespaces at the beginning or at the end, the function returns
** a copy of s. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	int					len;
	unsigned int		i;
	unsigned int		size;
	unsigned int		z;

	if (!s)
		return (NULL);
	size = ft_strlen((char*)s);
	len = size - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	z = 0;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
	{
		len--;
		z++;
	}
	size = (size < i + z) ? 0 : (size - i - z);
	if (!(str = ft_strnew(size)))
		return (NULL);
	str = ft_strncpy(str, (char*)s + i, size);
	return (str);
}
