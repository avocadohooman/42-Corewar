/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:01:08 by npimenof          #+#    #+#             */
/*   Updated: 2021/01/26 23:04:30 by npimenof         ###   ########.fr       */
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
