/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:30:32 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 14:22:31 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strdup() function allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it. The pointer may subsequently
** be used as an argument to the function free(3). If insufficient memory
** is available, NULL is returned and errno is set to ENOMEM.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	dest = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
