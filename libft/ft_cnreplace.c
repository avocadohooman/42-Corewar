/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:59:29 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/05 16:08:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cnreplace(char *str, char *nreplace, char new_c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_strcspn(&str[i], nreplace))
		{
			i++;
			continue;
		}
		str[i] = new_c;
		i++;
	}
	return (str);
}
