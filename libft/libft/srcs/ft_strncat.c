/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:42:33 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 18:03:00 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Same as strcat
** The strncat() function appends not more than n characters from s2,
** and then adds a terminating `\0'.
** functioin return pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	i = 0;
	len_src = ft_strlen(s2);
	len_dst = ft_strlen(s1);
	n = (len_src < n) ? len_src : n;
	while (n--)
	{
		*(s1 + len_dst + i) = *(s2 + i);
		i++;
	}
	*(s1 + len_dst + i) = '\0';
	return (s1);
}
