/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:16:50 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/19 16:17:01 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_lfmod(long double x, long double y)
{
	long double			result;
	unsigned long long	i;

	i = x / y;
	result = x - (i * y);
	return (result);
}
