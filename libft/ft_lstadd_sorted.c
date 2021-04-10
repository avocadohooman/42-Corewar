/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 10:48:57 by npimenof          #+#    #+#             */
/*   Updated: 2020/02/26 10:52:54 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_sorted(t_list **head, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!(*head) || (*head)->content > new->content)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		tmp = *head;
		while (tmp->next != NULL && tmp->next->content < new->content)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
