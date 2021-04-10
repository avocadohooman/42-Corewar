/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:48:56 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 11:52:16 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  take a string as argument and return a new string with upcase characters
*/

#include "libft.h"

char	*ft_strupcase(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	return (s);
}
