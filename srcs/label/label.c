/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:01:08 by npimenof          #+#    #+#             */
/*   Updated: 2021/03/25 16:26:58 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label.h"

t_label	*new_label(char *label)
{
	t_label *label_node;

	if (!(label_node = ft_memalloc(sizeof(t_label))))
		return (NULL);
	label_node->label = ft_strdup(label);
	return (label_node);
}

void	label_push(t_label **list, t_label *label)
{
	ft_lstpush((t_list **)&(*list), (t_list *)label);
}

int		label_value(t_label *head, char *label)
{
	while (head)
	{
		if (!(ft_strcmp(label, head->label)))
			return (head->value);
		head = (t_label *)head->nexxt.next;
	}
	return (-1);
}
