/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:05:52 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 12:19:33 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalpha() function tests for any character for which isupper(3)
** or islower(3) is true. The value of the argument must be representable as an
** unsigned char or the value of EOF.
** The isalpha() function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

#include "libft.h"

int		ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
