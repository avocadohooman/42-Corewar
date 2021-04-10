/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:57:42 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/19 11:37:07 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_get_base_char(unsigned long long n, int base)
{
	char	symbols[16];

	ft_strncpy(symbols, "0123456789abcdef", base);
	if (n > (unsigned long long)(base - 1))
		return (symbols[n % base]);
	return (symbols[n]);
}

static int		ft_count_digits(unsigned long long n, int base)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

static void		ft_splitdigits_base(unsigned long long n, int b, int l, char *s)
{
	if (n >= (unsigned long long)b)
	{
		ft_splitdigits_base(n / b, b, l - 1, s);
		ft_splitdigits_base(n % b, b, l, s);
	}
	else
		s[l] = ft_get_base_char(n, b);
}

char			*ft_itoa_base(unsigned long long n, int base)
{
	int		len;
	char	*num;

	len = ft_count_digits(n, base);
	if (!(num = ft_strnew(len)))
		return (NULL);
	ft_splitdigits_base(n, base, len - 1, num);
	return (num);
}
