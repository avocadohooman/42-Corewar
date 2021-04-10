/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:56:42 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/23 12:55:53 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*first;

	new = NULL;
	first = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			if (!new)
			{
				new = f(tmp);
				first = new;
			}
			else
			{
				new->next = f(tmp);
				new = new->next;
			}
			tmp = tmp->next;
		}
	}
	return (first);
}
