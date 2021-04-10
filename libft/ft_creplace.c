/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:29:09 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/05 16:02:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_creplace(char *str, char *replace, char new_c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strcspn(&str[i], replace))
			str[i] = new_c;
		i++;
	}
	return (str);
}
