/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:27:15 by npimenof          #+#    #+#             */
/*   Updated: 2020/03/08 13:27:42 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **head)
{
	t_list	*current;
	t_list	*nxt;
	t_list	*prev;

	nxt = NULL;
	prev = NULL;
	current = *head;
	while (current)
	{
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;
	}
	*head = prev;
}
