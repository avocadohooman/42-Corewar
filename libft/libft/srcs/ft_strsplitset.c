/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:42:52 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 13:25:32 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	seperate_char(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_words(char *str, const char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] && seperate_char(str[i], charset))
		i++;
	if (str[i] && !seperate_char(str[i], charset))
		count = 1;
	while (str[i])
	{
		if (!seperate_char(str[i], charset)
		&& seperate_char(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

static int	word_size(char *str, char const *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && !seperate_char(str[i], charset))
	{
		size++;
		i++;
	}
	return (size);
}

char		**ft_strsplitcharset(char *str, const char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	tab = (char**)malloc(sizeof(char*) * count_words(str, charset) + 1);
	if (tab == NULL)
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!seperate_char(str[i], charset))
		{
			if (index == -1 || seperate_char(str[i - 1], charset))
			{
				if (!(tab[++index] = (char*)malloc(sizeof(char) * (word_size(
						str + i, charset) + 1))))
					return (NULL);
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	tab[++index] = 0;
	return (tab);
}
