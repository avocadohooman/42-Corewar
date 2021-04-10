/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:36:43 by npimenof          #+#    #+#             */
/*   Updated: 2020/11/02 15:39:09 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			if (del)
				del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}
