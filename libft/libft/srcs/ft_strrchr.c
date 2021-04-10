/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:39:04 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 11:07:32 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strrchr() function locates the last occurrence of c (converted to a char)
** in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
** function return a pointer to the located character, or
** NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char*)&s[i]);
	i = i - 1;
	while (s[i] && i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char*)&s[i]);
		}
		i--;
	}
	return (0);
}
