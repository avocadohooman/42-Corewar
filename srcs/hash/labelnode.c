/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:01:08 by npimenof          #+#    #+#             */
/*   Updated: 2021/02/03 10:48:14 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "label.h"
#include <stdio.h>

t_label		*new_label(char *label_key, int value)
{
	t_label	*label;

	if (!(label = ft_memalloc(sizeof(t_label))))
		return (NULL);
	label->value = value;
	label->node.key = label_key;
	return (label);
}

t_label		*label_upsert(t_hash **map, t_label *label)
{
	t_label	*label_copy;

	if (!(label_copy = new_label(label->node.key, label->value)))
		return (NULL);
	if (!hash_upsert(map, (t_hashnode *)label_copy))
		return (NULL);
	return (label);
}

t_label		*label_findby_key(t_hash *map, char *key)
{
	t_label	*label;
	t_label	*label_copy;

	if (!(label = (t_label *)hash_findby_key(map, key)))
		return (NULL);
	if (!(label_copy = ft_memalloc(sizeof(t_label))))
		return (NULL);
	ft_memcpy(label_copy, label, sizeof(t_label));
	return (label_copy);
}

t_label1	*new_label1(char *label)
{
	t_label1 *label_node;

	if (!(label_node = ft_memalloc(sizeof(t_label1))))
		return (NULL);
	label_node->label = ft_strdup(label);
	return (label_node);
}

void	push(t_label1 **list, t_label1 *label)
{
	ft_lstpush((t_list **)&(*list), (t_list *)label);
}

void	ft_labeladd(t_label1 **alst, t_label1 *new)
{
	if (*alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (new)
		*alst = new;
}

int		label_value(t_label1 *head, char *label)
{
	while (head)
	{
		if (!(ft_strcmp(label, head->label)))
		{
			printf("match with: %s -- label_value: %d\n", head->label, head->value);
			return (head->value);
		}
		head = (t_label1 *)head->nexxt.next;
	}
	return (-1);
}