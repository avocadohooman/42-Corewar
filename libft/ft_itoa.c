/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:42:59 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/17 11:57:32 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long n)
{
	long	nb;
	char	*num;
	int		len;

	nb = (long)n;
	len = ft_ndigits((long)nb);
	if (nb < 0)
		len++;
	if (!(num = ft_strnew(len)))
		return (NULL);
	ft_splitdigits((long)nb, len - 1, num);
	return (num);
}
