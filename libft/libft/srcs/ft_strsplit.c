/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:10:45 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 13:26:49 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings
** (all ending with ’\0’, including the array itself)
** obtained by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
** Example: ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**strplit;

	if (!s || !c)
		return (NULL);
	str = ft_strnew(2);
	if (!str)
		return (NULL);
	str[0] = c;
	strplit = ft_strsplitcharset((char*)s, str);
	ft_strdel(&str);
	return (strplit);
}
