/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:30:11 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/19 13:38:12 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ndigits(int n)
{
	int		count;
	long	nb;

	nb = (long)n;
	if (nb == 0)
		return (1);
	if (n < 0)
		nb *= -1;
	count = 0;
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
