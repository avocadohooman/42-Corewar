/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:12:03 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 17:37:47 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strclen(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * ft_nwords(s, c) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_nwords(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(arr[k] = ft_strnew(ft_strclen(&s[i], c))))
			return (NULL);
		j = 0;
		while (s[i] != c && s[i])
			arr[k][j++] = s[i++];
		k++;
	}
	arr[k] = NULL;
	return (arr);
}
