/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:27:50 by hopham            #+#    #+#             */
/*   Updated: 2019/10/23 17:44:35 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isalnum() function tests for any character for which isalpha(3)
** or isdigit(3) is true.
** The value of the argument must be representable as an unsigned char or the
** value of EOF.
** The isalnum() function returns zero if the character tests false
** and returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
