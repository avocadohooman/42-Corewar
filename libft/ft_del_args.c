/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:30:34 by npimenof          #+#    #+#             */
/*   Updated: 2020/02/13 15:39:33 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void	ft_del(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void		ft_del_args(int count, ...)
{
	va_list		a_list;
	void		*ptr;

	va_start(a_list, count);
	while (count--)
	{
		ptr = va_arg(a_list, void *);
		ft_del(&ptr);
	}
	va_end(a_list);
}
